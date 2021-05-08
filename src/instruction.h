#include "opcodes.h"
#include <stdint.h>

#ifndef VM_H
#define VM_H
struct Instruction {
	Opcode op;
	uint8_t flags;
};
#endif