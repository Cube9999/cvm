#ifndef CVM_OPCODES_H
#define CVM_OPCODES_H

enum Opcode {
    // Register
    LOADCONST, // Loads a constant onto the register
    // Arithmetic
    ADD, // Addition
    SUB, // Subtraction
    MUL, // Multiplication
    // Comparison
    EQUAL, // is equal to
    GT, // Greater than
    LT, // Less than
    // Other
    CALL, // Calls a function
    JUMP, // Unconditional jump
};

typedef enum Opcode Opcode;

#endif // CVM_OPCODES_H
