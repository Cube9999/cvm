#ifndef CVM_VM_H
#define CVM_VM_H
#include "./vmstatus.h"
#include "./stack.h"
#include "bytecode.h"

#define DEBUG

struct Vm {
	Stack stack;
	int ip;
	int regs[3];
	byte cbit;
};

VmStatus vm_mainloop(struct Vm vm, Bytecode bytecode);

#endif // CVM_VM_H
