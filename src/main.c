#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./stack.h"
#include "./opcodes.h"
#include "./instruction.h"
#include "./bytecode.h"
#include "vm.h"

#define LEN(x) (sizeof(x) / sizeof(x[0]))

#ifndef DEBUG
int main(int argc, char* argv[])
{
	const char* path = argv[1];
	Bytecode bytecode;
	struct Vm vm;
	read_from_file(&bytecode, path);

	return vm_mainloop(vm, &bytecode);
}
#else
int main() {
	Instruction instructions[] = {
		{
			EQ, {1, 2, 2}
		},
		{
			JUMP, {3}
		},
		{
			PRINT, {'h'}
		},
		{
			JUMP, {0}
		},
		{
			EXIT, {0}
		}
	};

	Bytecode bytecode;
	struct Vm vm;

	to_bytecode(&bytecode, instructions, LEN(instructions));
	/* Keep in mind this (atleast on my build) generates the file on build/. NOT on the root folder */
	save_to_file(&bytecode, "test.bin");

	return vm_mainloop(vm, &bytecode);
}
#endif
