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
 * f_swap - print all nodes in a stack
 * @stack: double linked list
 * @line_number: integer
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;

	(*stack)->prev = tmp;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack) = (*stack)->prev;
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
