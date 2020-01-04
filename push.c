#include "monty.h"

void f_push(stack_t **stack, unsigned int line_number)
{

	/*char *number = NULL;*/
	stack_t *new_num = NULL;

	/*
	  here we have t ouse a global array that contains
	  that contains the  tokenize line and use this as number	
	*/
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
	printf("Number added good job\n");
	add_dnodeint(stack, new_num);
	printf("Nice job\n");
	printf("number of line %d\n", line_number);
}
