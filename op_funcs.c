#include "monty.h"

/**
 * activate_op - execute the correct funtion
 * @stack: list
 * @line_number: integer
 * @file: file to open
 */
void activate_op(stack_t **stack, unsigned int line_number, char *file)
{
	char *user_buffer = NULL, *delim = "\n ";
	int i = 0, state = 0;
	FILE *file_open;
	size_t buffer_size = 0;
	instruction_t funcs[] = {
		{"push", f_push}, {"pall", f_pall},
		{"pint", f_pint}, {NULL, NULL}
	};

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file%s\n", file);
		exit(EXIT_FAILURE);
	}
	file_open = fopen(file, "r");
	if (file_open == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while (getline(&user_buffer, &buffer_size, file_open) > 0)
	{
		line_number++;
		input[0] = strtok(user_buffer, delim);
		input[1] = strtok(NULL, delim);
		i = 0;
		while (funcs[i].opcode != NULL)
		{
			if (strcmp(funcs[i].opcode, input[0]) == 0)
			{
				funcs[i].f(stack, line_number);
				state = 1;
				break;
			} i++;
		}
		if (state == 1)
			continue;
		fclose(file_open);
		exit(EXIT_FAILURE);
	}
}
