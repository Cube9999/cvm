#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./stack.h"
#include "./opcodes.h"
#include "./instruction.h"
#include "./bytecode.h"
#include "vm.h"

#define LEN(x) (sizeof(x) / sizeof(x[0]))


int main()
{
	Instruction instructions[] = {
		{
			ADD, {2, 5}
		},
		{
			GETCONST, {0}
		},
		{
			HALT, {0}
		}
	};

	Bytecode bytecode;
	struct Vm vm;

	to_bytecode(&bytecode, instructions, LEN(instructions));
	/* Keep in mind this (atleast on my build) generates the file on build/. NOT on the root folder */
	save_to_file(&bytecode, "test.bin");

	return vm_mainloop(vm, &bytecode);
}
