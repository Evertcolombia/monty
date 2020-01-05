#include "monty.h"

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
