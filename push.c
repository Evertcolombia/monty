#include "monty.h"

void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_num = NULL;
	char *num = NULL;

	if (input[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		freeStack(stack) /*fclose(file_open)*/;
		exit(EXIT_FAILURE);
	}
	num = input[1];
	/*if (isdigit(number) == 0)
	{
		
		  free stack and file
		
		printf("eroor is not number %d\n", line_number);
		exit(EXIT_FAILURE);
	}*/
	new_num = malloc(sizeof(stack_t));
	if (new_num == NULL)
	{
		freeStack(stack); /*fclose(file_open)*/
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_num->n = atoi(num);
	add_dnodeint(stack, new_num);
}

void f_pall(stack_t **stack, __attribute((unused))unsigned int line_number)
{
	stack_t *tmp = NULL;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

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
