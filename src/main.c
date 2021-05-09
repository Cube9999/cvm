#include <stdio.h>
#include "./stack.h"
#include "./opcodes.h"

int main()
{
    Stack* stack = create_stack();
    push_stack(stack, 10);
    push_stack(stack, 20);
    pop_stack(stack);
    printf("%d", *top_stack(stack));
    terminate_stack(stack);
	return 0;
}
