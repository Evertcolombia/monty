#include "monty.h"

void activate_op(stack_t **stack, unsigned int line_number, FILE *file_open)
{
	char *user_buffer = NULL, *line, *delim = "\n ";
	int i = 0, state = 0;
	size_t buffer_size = 0;
	instruction_t funcs[] = {
		{"push", f_push}, {"pall", f_pall},
		{"pint", f_pint}, {NULL, NULL}
	};

	if (!file_open)
	{
		printf("fail here\n");
	}
	printf("pasa\n");
	while (getline(&user_buffer, &buffer_size, file_open) > 0)
	{
		line = user_buffer, line_number++;
		input[0] = strtok(line, delim);
		input[1] = strtok(NULL, delim);
		while (funcs[i].opcode != NULL)
		{
			if (strcmp(funcs[i].opcode, input[0]) == 0)
			{
				printf("%s\n", funcs[i].opcode);
				funcs[i].f(stack, line_number);
        	                state = 1;
                	        break;
			} i++;
		}
		if (state == 1)
			continue;
		exit(EXIT_FAILURE);
	}
}
