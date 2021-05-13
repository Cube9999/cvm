#include "vm.h"
#include <stdlib.h>
#include <stdio.h>

VmStatus vm_mainloop(struct Vm vm, struct Bytecode bytecode)
{
	Instruction* instrs;
	Instruction cinstr;

	instrs = to_instructions(&bytecode);
	vm.ip = 0;
	vm.stack = create_stack();
	vm.regs[0] = 0;
	vm.regs[1] = 0;
	vm.regs[2] = 0;

	while (vm.ip != bytecode.length) 
	{
		printf("Executing instruction %d\n", vm.ip);
		cinstr = instrs[vm.ip];

		switch (cinstr.op) 
		{
		case LOADCONST:
			push_stack(&vm.stack, cinstr.args[0]);
			vm.ip++;
			break;
		case LOADCONSTR:
			if (cinstr.args[0] > 3)
				return ERROR_BADINSTR;
			push_stack(&vm.stack, vm.regs[cinstr.args[0]]);
		case GETCONST:
			if (cinstr.args[0] > 3)
				return ERROR_BADINSTR;
			vm.regs[cinstr.args[0]] = *top_stack(&vm.stack);
		case ADD:
			push_stack(&vm.stack, cinstr.args[0] + cinstr.args[1]);
			vm.ip++;
			break;
		case SUB:
			push_stack(&vm.stack, cinstr.args[0] - cinstr.args[1]);
			vm.ip++;
			break;
		case MUL:
			push_stack(&vm.stack, cinstr.args[0] * cinstr.args[1]);
			vm.ip++;
			break;
		}	
	}


	printf("============================ DEBUGGING INFO ============================\n");
	printf("--------------- STACK ------------\n");
	printf("STACK_SIZE = %d\n", vm.stack.total_size);
	for (int i = 0; i < vm.stack.total_size; ++i) 
	{
		printf("\tv=%d\ti=%d\n", vm.stack.stack[i], i);
	}
	printf("----------------------------------\n");
	printf("LAST IP = %d\nENDPTR == IP IS %s\n", vm.ip, (vm.ip == bytecode.length) ? "TRUE" : "FALSE");
	printf("--------------- REGS ------------\n");
	printf("\tr1=%d\tr2=%d\tr3=%d\n", vm.regs[0], vm.regs[1], vm.regs[2]);

	free_bytecode(&bytecode);
	free(instrs);
	return ERROR_SUCCESS;
}
