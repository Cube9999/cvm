#ifndef CVM_VMSTATUS_H
#define CVM_VMSTATUS_H

enum VmStatus {
	ERROR_SYNTAX,
	ERROR_UNKNOWN,
	ERROR_SUCCESS,
	ERROR_MAGICNUMBER,
	ERROR_BADINSTR,
	ERROR_ENDPTR_NOT_EQUAL,
};

typedef enum VmStatus VmStatus;
typedef char status_Code;

#endif // CVM_VMSTATUS_H
