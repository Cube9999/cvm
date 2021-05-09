#ifndef CVM_VMSTATUS_H
#define CVM_VMSTATUS_H

enum VmStatus {
	ERROR_SYNTAX,
	ERROR_UNKNOWN,
	ERROR_SUCCESS,
	ERROR_MAGICNUMBER
};

typedef enum VmStatus VmStatus;

#endif // CVM_VMSTATUS_H
