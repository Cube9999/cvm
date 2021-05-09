#ifndef CVM_STACK_H
#define CVM_STACK_H

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long stack_size;

struct Stack {
    byte* stack;
    stack_size total_size;
    stack_size allocated;
};

typedef struct Stack Stack;

Stack* create_stack();
void push_stack(Stack* stack, int value);
void pop_stack(Stack* stack);
byte* top_stack(Stack* stack);
void terminate_stack(Stack* stack);

#endif // CVM_STACK_H
