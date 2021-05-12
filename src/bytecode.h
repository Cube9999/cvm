#ifndef CVM_BYTECODE_H
#define CVM_BYTECODE_H
#include <stddef.h> // for size_t
#include "./instruction.h"
#include "./stack.h" // for byte

/*
	How to use, even though it's pretty obvious:

	Convert your instructions to a Bytecode with to_bytecode, from there you can save that to a file simply by calling save_to_file.
	When you want to extract the instructions from the file, you first call read_from_file which returns a 'Bytecode' and can be converted to instructions with to_instructions.
*/

struct Bytecode {
	byte* raw_data;
	size_t length;
};

typedef struct Bytecode Bytecode;

void to_bytecode(Bytecode* bytecode, Instruction* instructions, size_t length);
Instruction* to_instructions(Bytecode* bytecode);

void save_to_file(Bytecode* bytecode, const char* path);
Bytecode read_from_file(const char* path);

void free_bytecode(Bytecode* bytecode);

#endif // CVM_BYTECODE_H
