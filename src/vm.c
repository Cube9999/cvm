#include "vm.h"
#include "bitreader.h"

enum VmStatus vm_mainloop(struct Vm vm) 
{

	/* Check for the magic number */
	if (read32(vm.codebuff, 0) != 0x0743564D) 
	{
		return ERROR_MAGICNUMBER;
	}

	/* we set the IP to 4 because we want to skip the magic number */
	vm.IP = 4;
	while (vm.IP != vm.codesize)
	{

	}
}