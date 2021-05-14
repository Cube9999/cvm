#ifndef CVM_OPCODES_H
#define CVM_OPCODES_H
#include "./stack.h"

enum Opcode {
    /* OP           EXPLANATION */
    EXIT = 0x0,
    LOADCONST = 0x1,      /* Pushes an int into the stack */
    LOADCONSTR = 0x2,     /* Pushes the value of a register to the stack*/
    GETCONST = 0x3,       /* Gets the first value off the stack and puts in a register */
    ADD = 0x4,            /* Addition */
    SUB = 0x5,            /* Subtraction */
    MUL = 0x6,            /* Multiplication */
    CMP = 0x7,            /* Compare, sets the clear bit if equal */
    EQ = 0x8,             /* If equal, jump */
    JUMP = 0x9,           /* Unconditional jump */
    PRINT = 0xa,

};

typedef enum Opcode Opcode;
#endif // CVM_OPCODES_H
