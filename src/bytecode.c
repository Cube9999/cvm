#include "./bytecode.h"
#include <stdio.h>
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

void save_to_file(Bytecode* bytecode, const char* path) {
	FILE* file = fopen(path, "wb");
	int cursor = 0;
	for (size_t i = 0; i < bytecode->length; ++i) {
		byte buffer[4] = {bytecode->raw_data[cursor], bytecode->raw_data[++cursor], bytecode->raw_data[++cursor], bytecode->raw_data[++cursor]};
		cursor++;
		fwrite(buffer, sizeof(buffer), 1, file);
	}
	fclose(file);
}

void read_from_file(Bytecode* bytecode, const char* path) {
	/*
		my idea is to have the first 4 bytes store special information about the bytecode such as the instruction count, size, etc.
		But I've been trying to get this entire thing to run for so long that I no longer have the mental stamina to do anything here and just wanna be done with it.
		- vi
	*/
	FILE* file = fopen(path, "rb");
	size_t allocated_size = 4;
	size_t cursor = 0;
	byte* raw_data = malloc(allocated_size);
	int current_byte = getc(file);
	while (current_byte != EOF) {
		if (cursor == allocated_size) {
			allocated_size += 4;
			raw_data = realloc(raw_data, allocated_size); // FIXME: Performance
		}
		raw_data[cursor++] = current_byte;
		current_byte = getc(file);
	}
	fclose(file);
	bytecode->length = allocated_size / 4;
	bytecode->raw_data = raw_data;
}

void free_bytecode(Bytecode* bytecode) {
	free(bytecode->raw_data);
}
