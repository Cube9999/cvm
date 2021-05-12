#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./stack.h"
#include "./opcodes.h"
#include "./instruction.h"
#include "./bytecode.h"

int main()
{
	// The following instructions below do not really make sense, but is used for testing the bytecode.
	Instruction instructions[] = {
		{
			ADD, {1, 5}
		},
		{
			SUB, {3}
		},
		{
			MUL, {5, 7, 3}
		},
		{
			JUMP, {1}
		},
		{
			ADD, {3, 5}
		},
		{
			MUL, {3, 7}
		},
		{
			JUMP, {3, 10, 2}
		}
	};
	Bytecode bytecode;
	read_from_file(&bytecode, "test.bin");
	for (int i = 0; i < bytecode.length*4; ++i) {
		printf("%d ", bytecode.raw_data[i]);
	}
	//Bytecode bytecode;
	//to_bytecode(&bytecode, instructions, 7);
	//save_to_file(&bytecode, "test.bin");
	/*
	Instruction* L_instructions = to_instructions(&bytecode);
	for (int i = 0; i < bytecode.length; ++i) {
		Instruction current = L_instructions[i];
		printf("Opcode(%d) Args(%d, %d, %d)\n", current.op, current.args[0], current.args[1], current.args[2]);
	}
	free(L_instructions);
	*/
	return 0;
}
