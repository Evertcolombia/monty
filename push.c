#include "monty.h"

/**
 * f_push - push a new element to the stack
 * @stack: stack in dlinked
 * @line_number: number of the line
 *
 * Return: none
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_num = NULL;
	char *num = NULL;

	if (input[1] == NULL)
		return;
	num = input[1];

	new_num = malloc(sizeof(stack_t));
	if (new_num == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (is_number(num) == 0)
        {
                freeStack(*stack);
		free(new_num);
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }
	new_num->n = atoi(num);
	add_dnodeint(stack, new_num);
}

/**
 * f_pall - pall a new element to the stack
 * @stack: stack in dlinked
 * @line_number: number of the line
 *
 * Return: none
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void) line_number;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}
/**
 * f_pop - push a new element to the stack
 * @stack: stack in dlinked
 * @line_number: number of the line
 *
 * Return: none
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		printf("L%d: can't pop an empty", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	if ((*stack)->next != NULL)
	{
		/*tmp = (*stack)->prev;*/
		tmp->prev = (*stack)->prev->prev;
		/*free(*stack);*/
	}
	else
	{
		/*tmp = (*stack)->prev;*/
		printf("tmp->n : %d", tmp->n);
		/*tmp->prev = (*stack)->prev;*/
		/*free(*stack);*/
	}
	/*tmp->prev = (*stack)->prev;*/
}
