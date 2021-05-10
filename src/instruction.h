#ifndef CVM_INSTRUCTION_H
#define CVM_INSTRUCTION_H
#include "./opcodes.h"
#include <stdint.h>

/* NOTE: Because the flags are 1 bit only, we can't really reperesent them with a struct
   so here they're 1 byte instead */
struct Flags {
	byte firstArgIsAddr;
	byte secondArgIsAddr;
	byte regForarg1; /* This is 3 bits and not 1! (same for the one below) */
	byte regForarg2;
};


struct Instruction {
	Opcode op;
	struct Flags flags;
};

#endif
