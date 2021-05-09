#include "./stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* create_stack() {
    Stack stack;
    Stack* stack_ptr = &stack;
    stack.total_size = 10;
    stack.allocated = 0;
    stack.stack = malloc(stack.total_size * sizeof(byte));
    return stack_ptr;
}

void push_stack(Stack* stack, int value) {
    if (stack->allocated == stack->total_size) { // FIXME: This condition is not thread-safe in case we ever decided to add threading.
        //resize_stack(stack, stack->total_size + 10);
        stack->total_size *= 2;
        stack->stack = realloc(stack->stack, stack->total_size * sizeof(byte));
        stack->allocated /= 2;
    }
    stack->stack[stack->allocated++] = value;
}

void pop_stack(Stack* stack) {
    stack->stack[--stack->allocated] = 0;
}

byte* top_stack(Stack* stack) {
    return &stack->stack[stack->allocated-1];
}

void terminate_stack(Stack* stack) {
    // no cube, there are no smart pointers in C, you actually have to call terminate_stack yourself!
    free(stack->stack);
}
