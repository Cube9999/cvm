#ifndef CVM_OPCODES_H
#define CVM_OPCODES_H
#include "./stack.h"

enum Opcode {
    /* OP           EXPLANATION */
    LOADCONST,      /* Pushes an int into the stack */
    LOADCONSTR,     /* Pushes the value of a register to the stack*/
    GETCONST,       /* Gets the first value off the stack and puts in a register */
    ADD,            /* Addition */
    SUB,            /* Subtraction */
    MUL,            /* Multiplication */
    CMP,            /* Compare, sets the clear bit if equal */
    EQ,             /* If equal, jump */
    JUMP,           /* Unconditional jump */

};

typedef enum Opcode Opcode;
#endif // CVM_OPCODES_H
