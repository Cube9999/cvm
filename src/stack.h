#ifndef CVM_STACK_H
#define CVM_STACK_H

typedef unsigned char byte;
typedef unsigned short word;

struct Stack {
    byte stack[10];
    int total_size;
    int allocated;
};

typedef struct Stack Stack;

Stack* create_stack();
void push_stack(Stack* stack, int value);
void pop_stack(Stack* stack);
byte* top_stack(Stack* stack);

#endif // CVM_STACK_H
