#pragma once


// Unsigned typedefs

typedef unsigned char   byte;
typedef unsigned short  word;
typedef unsigned int    dword;
typedef unsigned long   qword;

// Signed typedefs
typedef signed char     sbyte;
typedef signed short    int16;
typedef signed int      int32;
typedef signed long     int64;

// Bools (for use in C89/C90 as there's no stdint.h, use "bool" in C++)
#ifndef __cplusplus
typedef int             bool;
#define true  1
#define false 0
#endif
