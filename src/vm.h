#ifndef CVM_VM_H
#define CVM_VM_H
#include "./vmstatus.h"
#include "./stack.h"

struct Vm {
	Stack stack;
	int ip;
	int registers[3];
	int codesize; // used internally
	byte* codebuff;
};

VmStatus vm_mainloop(struct Vm vm);

#endif // CVM_VM_H
