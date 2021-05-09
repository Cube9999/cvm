#ifndef CVM_INSTRUCTION_H
#define CVM_INSTRUCTION_H
#include "./opcodes.h"
#include <stdint.h>

struct Instruction {
	Opcode op;
	uint8_t* flags;
};

#endif
