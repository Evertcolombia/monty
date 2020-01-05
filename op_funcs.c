#include "monty.h"

void activate_op(stack_t **stack, unsigned int line_number)
{
	int i = 0

	instruction_t funcs[] = {
		{"push", f_push}, {"pall", f_pall},
		{"pint", f_pint}, {NULL, NULL}
	};

	if (input[1] == NULL)
		return;
	while (funcs[i].opcode != NULL)
                {
                        if (strcmp(funcs[i].opcode, input[0]) == 0)
                        {
                                funcs[i].f(stack, num_line);
                                /*state = 1;*/
                               	/*break;*/
				return;
		} i++;
	}
	/*if (state == 1)
		continue;
	exit(EXIT_FAILURE);*/

	if (strlen(input[1]) != 0 && input[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, operation);
		exit(EXIT_FAILURE);
	}
}
