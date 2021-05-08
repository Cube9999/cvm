#ifndef CVM_OPCODES_H
#define CVM_OPCODES_H

enum Opcode {
    LOADC,
    ADD,
    SUB,
    MUL,
    JUMP
};

typedef enum Opcode Opcode;

#endif // CVM_OPCODES_H
