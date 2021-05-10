/*! TODO: Make a serializer library and then port the vm to it, it's not a good idea to have the serializer here. !*/
#include "vm.h"
#include "bitreader.h"
#include "instruction.h"
#include <limits.h>

#define isbitset(x, y) (x & (1<<y))

/* Stolen from stackoverflow because I got mad at bitwise again! */
unsigned getbits(unsigned value, unsigned offset, unsigned n)
{
  const unsigned max_n = CHAR_BIT * sizeof(unsigned);
  if (offset >= max_n)
    return 0; /* value is padded with infinite zeros on the left */
  value >>= offset; /* drop offset bits */
  if (n >= max_n)
    return value; /* all  bits requested */
  const unsigned mask = (1u << n) - 1; /* n '1's */
  return value & mask;
}


struct Flags vm_parseflags(byte aflags) 
{
	/* This is how the flags work:
		bit #1 - if set, the 1st instruction is an address (like PUSH 0x1000) otherwise it's a register (PUSH R1)
		bit #2 - same as above but with arg #2, unset if the instruction only has 1 arg
		bit #3-6 - Defines what register is being used (001 is r1, 010 is r2 and 011 is r3), zeros if instruction does not have a second argument or it isn't a register
		bit #6-8 - Same as above but with arg #2, zeros if instruction does not have a second argument or it isn't a register
	 */

	struct Flags flags;

	flags.firstArgIsAddr = isbitset(aflags, 0) ? 1 : 0;
	flags.secondArgIsAddr = isbitset(aflags, 1) ? 1 : 0;

	flags.regForarg1 = getbits(aflags, 3, 3);
	flags.regForarg2 = getbits(aflags, 6, 3);
	
	return flags;

}

VmStatus vm_mainloop(struct Vm vm)
{

	vm.stack = create_stack();
	/* Check for the magic number */
	if (read32(vm.codebuff, 0) != 0x0743564D) /* \07CVM */
	{
		return ERROR_MAGICNUMBER;
	}

	vm.ip = 4; /* We start from 4 to skip the magic number */

	while (vm.ip != vm.endptr) 
	{
		struct Instruction currinstr;
		currinstr.flags = vm_parseflags(read8(vm.codebuff, vm.ip + 1));
		currinstr.op = read8(vm.codebuff, vm.ip);

		/* Flags might be corrupted, we dont want to continue if that's the case so we crash */
		if (currinstr.flags.firstArgIsAddr && currinstr.flags.regForarg1 == 0 ||
			 currinstr.flags.secondArgIsAddr && currinstr.flags.regForarg2 == 0) 
			 {
				return ERROR_BADINSTR;
			 }

		/* Finally, we get to the actual execution! This will be fun... */
		switch (currinstr.op) 
		{
		case LOADCONST:
			if (currinstr.flags.firstArgIsAddr) 
			{
				/* TODO: Add support for 32 bit addresses */
				vm.registers[1] = read16(vm.codebuff, vm.ip + 2);
				vm.ip += 4; /* One to skip to the next instruction and flag, and the other two because of the 16 bit int */
			}
			else 
			{
				vm.registers[1] = currinstr.flags.regForarg1;
				vm.ip += 2; /* Here we don't need to jump 4 bytes because there's no 16 bit int */
			}
			break;
		case ADD:
			if (currinstr.flags.firstArgIsAddr) 
			{

			}
			break;
		}

	}

	return ERROR_SUCCESS;
}
