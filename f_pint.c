#include "monty.h"

void f_pint(stack_t **stack, unsigned int line_number)
{

	(void) line_number;
	if (*stack == NULL)
	{
		printf("Error messgae\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);	
}
