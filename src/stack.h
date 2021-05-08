#include <stdint.h>
#ifndef CVM_STACK_H
#define CVM_STACK_H

struct Stack {
    uint8_t stack[10];
    int pointer;
    int total_size;
    int allocated;
};

typedef struct Stack Stack;

Stack* create_stack() {
    Stack stack;
    Stack* stack_ptr = &stack;
    stack.pointer = -1;
    stack.total_size = 10;
    stack.allocated = 0;
    return stack_ptr;
}

void push_stack(Stack* stack, int value) {
    stack->stack[stack->allocated++] = value;
    if (stack->total_size == stack->allocated) { // FIXME: This condition is not thread-safe in case we ever decided to add threading.

    }
}

void pop_stack(Stack* stack) {
    stack->stack[--stack->allocated] = 0;
}

int top_stack(Stack* stack) {
    return stack->stack[stack->allocated-1];
}

#endif // CVM_STACK_H
