#include "monty.h"

/**
 * add_dnodeint - insert a node in a header list
 * @head: double pointer to the list
 * @n: integer with value
 *
 * Return: pointer to new node
 */
void add_dnodeint(stack_t **stack, stack_t *new_node)
{

	
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
