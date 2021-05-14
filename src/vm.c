#include "vm.h"
#include <stdlib.h>
#include <stdio.h>

bool vm_mainloop(struct Vm vm, Bytecode* bytecode)
{
	Instruction* instrs;
	Instruction cinstr;

	instrs = to_instructions(bytecode);
	vm.ip = 0;
	vm.stack = create_stack();
	vm.regs[0] = 0;
	vm.regs[1] = 0;
	vm.regs[2] = 0;

	while (vm.ip != bytecode->length)
	{
#ifdef DEBUG
		printf("Executing instruction %d\n", vm.ip);
#endif
		cinstr = instrs[vm.ip];

		switch (cinstr.op)
		{
		case HALT:
			free_bytecode(bytecode);
			free(instrs);
			return (cinstr.args[0] == EXIT_SUCCESS || cinstr.args[0] == EXIT_FAILURE) ? cinstr.args[0] : EXIT_FAILURE;
		case LOADCONST:
			push_stack(&vm.stack, cinstr.args[0]);
			vm.ip++;
			break;
		case LOADCONSTR:
			push_stack(&vm.stack, vm.regs[cinstr.args[0]]);
			vm.ip++;
		case GETCONST:
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
		case CMP:
			if (cinstr.args[0] == cinstr.args[1]) // this can be vm.cbit = (cinstr.args[0] == cinstr.args[1])
				vm.cbit = 1; /* Set the carry bit */
			else
				vm.cbit = 0; /* Unset the cbit incase it was set */
			vm.ip++;
			break;
		case EQ:
			/* TODO: Overflow checking */
			if (vm.cbit) // (potential issue) A fallthrough may occur is vm.cbit is 0.
				vm.ip = cinstr.args[0]; /* Jump to arg1 */
				break;
		case JUMP:
			vm.ip = cinstr.args[0]; /* Jump to arg1 */
			break;
		case PRINT:
			printf("%c", cinstr.args[0]);
			vm.ip++;
			break;
		default:
#ifdef DEBUG
			printf("UNKOWN INSTRUCTION %x. IGNORING..", cinstr.op);
#else
			return EXIT_FAILURE;
#endif
		}
	}

#ifdef DEBUG
	printf("============================ DEBUGGING INFO ============================\n");
	printf("--------------- STACK ------------\n");
	printf("STACK_SIZE = %d\n", vm.stack.total_size);
	for (int i = 0; i < vm.stack.total_size; ++i)
	{
		printf("\tv=%d\ti=%d\n", vm.stack.stack[i], i);
	}
	printf("----------------------------------\n");
	printf("LAST IP = %d\nENDPTR == IP IS %s\n", vm.ip, (vm.ip == bytecode->length) ? "TRUE" : "FALSE");
	printf("--------------- REGS ------------\n");
	printf("\tr1=%d\tr2=%d\tr3=%d\n", vm.regs[0], vm.regs[1], vm.regs[2]);
#endif

	free_bytecode(bytecode);
	free(instrs);
	return EXIT_FAILURE; // Should always end with a HALT to indicate a successful end.
}
