#ifndef CVM_VMSTATUS_H
#define CVM_VMSTATUS_H
#include "./stack.h" // for byte

// We probably should only have an EXIT_SUCCESS and an EXIT_FAILURE, it's not the vm's responsibility to figure out why.
enum VmStatus {
	ERROR_SYNTAX,
	ERROR_UNKNOWN,
	ERROR_SUCCESS,
	ERROR_FAILURE,
	ERROR_MAGICNUMBER,
	ERROR_BADINSTR,
	ERROR_ENDPTR_NOT_EQUAL,
};

typedef enum VmStatus VmStatus;
typedef char status_Code;

#endif // CVM_VMSTATUS_H
