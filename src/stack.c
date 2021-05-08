#include "./stack.h"

Stack* create_stack() {
    Stack stack;
    Stack* stack_ptr = &stack;
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

byte* top_stack(Stack* stack) {
    return &stack->stack[stack->allocated-1];
}
