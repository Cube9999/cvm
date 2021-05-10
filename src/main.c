#include <stdio.h>
#include "./stack.h"
#include "./opcodes.h"

int main()
{
    Stack stack = create_stack();
    for (int i = 0; i < 45; ++i) {
         printf("total size: %d | total allocated: %d\n", stack.total_size, stack.allocated);
        push_stack(&stack, i);
    }
    printf("%d", *top_stack(&stack));
    terminate_stack(&stack);
	return 0;
}
