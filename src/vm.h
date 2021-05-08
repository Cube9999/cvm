#include "vmstatus.h"
#include "stack.h"
#ifndef VM_H
#define VM_H

struct Vm {
	Stack stack;
	int IP;

	int r1;
	int r2;
	int r3;

	int codesize; // used internally
};

VmStatus vm_mainloop(struct Vm vm);

#endif
