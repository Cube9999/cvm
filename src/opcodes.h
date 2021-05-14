#ifndef CVM_OPCODES_H
#define CVM_OPCODES_H
#include "./stack.h"

enum Opcode {
    /* OP           EXPLANATION */
    LOADCONST = 1,      /* Pushes an int into the stack */
    LOADCONSTR = 2,     /* Pushes the value of a register to the stack*/
    GETCONST = 3,       /* Gets the first value off the stack and puts in a register */
    ADD = 4,            /* Addition */
    SUB = 5,            /* Subtraction */
    MUL = 6,            /* Multiplication */
    CMP = 7,            /* Compare, sets the clear bit if equal */
    EQ = 8,             /* If equal, jump */
    JUMP = 9,           /* Unconditional jump */
    PRINT = 10,
    HALT = 11,

};

typedef enum Opcode Opcode;
#endif // CVM_OPCODES_H
