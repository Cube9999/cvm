#ifndef CVM_VM_H
#define CVM_VM_H
#include <stdbool.h> // for bool
#include "./vmstatus.h"
#include "./stack.h"
#include "bytecode.h"

#define DEBUG
//#undef DEBUG

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

struct Vm {
	Stack stack;
	int ip;
	int regs[3];
	byte cbit;
};

bool vm_mainloop(struct Vm vm, Bytecode* bytecode);

#endif // CVM_VM_H
