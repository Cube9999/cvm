#ifndef CVM_INSTRUCTION_H
#define CVM_INSTRUCTION_H
#include "./stack.h" // for word
#include "./opcodes.h"
#include <stdint.h>

#define MAX_ARGS 3

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
	word args[MAX_ARGS];
	struct Flags flags;
};

typedef struct Instruction Instruction;

#endif
