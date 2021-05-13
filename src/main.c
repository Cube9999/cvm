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
	to_bytecode(&bytecode, instructions, 2);
	save_to_file(&bytecode, "test.bin");
	
	struct Vm vm;


	if (vm_mainloop(vm, bytecode)) 
	{
		printf("Sucessfully executed code!");
	}

	free_bytecode(&bytecode);

	return 0;
}
