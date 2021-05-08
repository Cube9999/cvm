#ifndef VMSTATUS_H
#define VMSTATUS_H

enum VmStatus {
	ERRO_SYNTAX,
	ERROR_UNKNOWN,
	ERROR_SUCCESS,
	ERROR_MAGICNUMBER
};

typedef enum VmStatus VmStatus;

#endif
