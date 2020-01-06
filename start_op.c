#include "monty.h"
/**
 * start_op - initializes correct function
 * @stack: dlined list
 * @line_number: unsigned int
 *
 */
void start_op(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t funcs[] = {
		{"push", f_push}, {"pall", f_pall},
		{"pint", f_pint}, {"pop", f_pop},
		{"swap", f_swap}, {"add", f_add},
		{NULL, NULL}
	};
	while (funcs[i].opcode != NULL)
	{
		if (strcmp(funcs[i].opcode, input[0]) == 0)
		{
			funcs[i].f(stack, line_number);
			break;
		} i++;
	}
}
