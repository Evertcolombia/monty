#include "monty.h"

void f_push(stack_t **stack, __attribute((unused))unsigned int line_number)
{
	stack_t *new_num = NULL;

	if (input[1] == NULL)
	{
		printf("Error is not a number here\n");
		/*Free stack and file*/
		exit(EXIT_FAILURE);
	}
	
	/*if (isdigit(number) == 0)
	{
		
		  free stack and file
		
		printf("eroor is not number %d\n", line_number);
		exit(EXIT_FAILURE);
	}*/

	new_num = malloc(sizeof(stack_t));
	if (new_num == NULL)
	{
		/*
                  free stack and file
                */
		printf("error malloc failed\n");
		/*exit(EXIT_FAILURE);*/
		exit(0);
	}

	new_num->n = atoi(input[1]);
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
	/*while (tmp != NULL)
		tmp = tmp->next;*/
	printf("will free %d\n", tmp->n);
	/*free(tmp);*/
}
