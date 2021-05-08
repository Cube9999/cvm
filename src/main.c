#include <stdio.h>
#include "./stack.h"

int main()
{
    Stack* stack = create_stack();
    push_stack(stack, 10);
    printf("%d", *top_stack(stack));
	return 0;
}
