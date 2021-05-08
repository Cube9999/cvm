#include <stdio.h>
#include "./stack.h"
#include "./opcodes.h"


int main()
{
    Stack* stack = create_stack();
    for (int i = 0; i < 10; ++i) {
        push_stack(stack, i);
    }
    printf("%d", top_stack(stack));
	return 0;
}
