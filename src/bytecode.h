#ifndef CVM_BYTECODE_H
#define CVM_BYTECODE_H
#include "./instruction.h"

char* to_bytecode(Instruction* instructions);
Instruction* to_instructions(char* bytecode);

#endif // CVM_BYTECODE_H
