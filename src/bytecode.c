#include "./bytecode.h"
#include <stdlib.h>

void to_bytecode(Bytecode* bytecode, Instruction* instructions, size_t length) {
	bytecode->length = length;
	byte* buffer = malloc(length * 4);
	int cursor = 0;
	for (size_t i = 0; i < length; ++i) {
		Instruction current_instruction = instructions[i];
		buffer[cursor] = current_instruction.op;
		buffer[++cursor] = current_instruction.args[0];
		buffer[++cursor] = current_instruction.args[1];
		buffer[++cursor] = current_instruction.args[2];
		cursor++;
	}
	bytecode->raw_data = buffer;
}

Instruction* to_instructions(Bytecode* bytecode) {
	Instruction* instructions = malloc(sizeof(Instruction) * bytecode->length);
	int cursor = 0;
	for (size_t i = 0; i < bytecode->length; ++i) {
		Instruction instruction;
		instruction.op = bytecode->raw_data[cursor];
		instruction.args[0] = bytecode->raw_data[++cursor];
		instruction.args[1] = bytecode->raw_data[++cursor];
		instruction.args[2] = bytecode->raw_data[++cursor];
		cursor++;
		instructions[i] = instruction;
	}
	return instructions;
}

void free_bytecode(Bytecode* bytecode) {
	free(bytecode->raw_data);
}
