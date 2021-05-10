#include "./stack.h"
#include "./vmstatus.h"
#include <stdlib.h>

Stack create_stack() {
    Stack stack;
    stack.total_size = 10;
    stack.allocated = 0;
    stack.stack = malloc(stack.total_size);
    for (byte i = 0; i < stack.total_size; ++i) {
		stack.stack[i] = 0;
    }
    return stack;
}

status_Code resize_stack(Stack* stack, stack_size new_size) {
	stack->stack = realloc(stack->stack, new_size);
	if (stack->stack != 0) {
		stack->total_size = new_size;
		return 1;
	} else {
		return 0;
	}
}

void push_stack(Stack* stack, int value) {
    if (stack->allocated == stack->total_size) { // FIXME: This condition is not thread-safe in case we ever decided to add threading.
        resize_stack(stack, stack->total_size * 2);
    }
    stack->stack[stack->allocated++] = value;
}

void pop_stack(Stack* stack) {
    stack->stack[--stack->allocated] = 0;
}

byte* top_stack(Stack* stack) {
	if (stack->allocated == 0)
		return &stack->stack[0];
    return &stack->stack[stack->allocated-1];
}

void terminate_stack(Stack* stack) {
    // no cube, there are no smart pointers in C, you actually have to call terminate_stack yourself!
    free(stack->stack);
}
