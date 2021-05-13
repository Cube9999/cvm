#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./stack.h"
#include "./opcodes.h"
#include "./instruction.h"
#include "./bytecode.h"
#include "vm.h"

main()
{
	Instruction instructions[] = {
		{
			ADD, {2, 2}
		},
		{
			GETCONST, {0}
		}
	};

	Bytecode bytecode;
	struct Vm vm;

	to_bytecode(&bytecode, instructions, 2);
	/* Keep in mind this (atleast on my build) generates the file on build/. NOT on the root folder */
	save_to_file(&bytecode, "test.bin");
	

	/* TODO: More error checking would be nice here */
	if (vm_mainloop(vm, bytecode)) 
	{
		printf("Sucessfully executed code!");
	}

	free_bytecode(&bytecode);

	return 0;
}
