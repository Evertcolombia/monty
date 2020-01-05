#include "monty.h"
/**
 * freeStack - free a dlinked list
 * @stack: list
 */
void freeStack(stack_t **stack)
{
	stack_t *tmp;

	while (tmp)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
	} free(tmp);
	free(*stack);
}
