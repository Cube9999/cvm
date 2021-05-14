#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./stack.h"
#include "./opcodes.h"
#include "./instruction.h"
#include "./bytecode.h"
#include "vm.h"

#define LEN(x) (sizeof(x) / sizeof(x[0]))


int main(int argc, char* argv[])
{
	const char* path = argv[1];
	Bytecode bytecode;
	struct Vm vm;
	read_from_file(&bytecode, path);

	return vm_mainloop(vm, &bytecode);
}
