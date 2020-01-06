#include "monty.h"
/**
 * freeStack - free a dlinked list
 * @stack: list
 */
void freeStack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
}
