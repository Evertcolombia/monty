#include "monty.h"
/**
 * f_pint - print all nodes in a stack
 * @stack: double linked list
 * @line_number: integer
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}


/**
 * f_add - print all nodes in a stack
 * @stack: double linked list
 * @line_number: integer
 */

void f_add(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	f_pop(stack, line_number);
	(*stack)->n = (*stack)->n + tmp;
}
