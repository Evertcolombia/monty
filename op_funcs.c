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
	int state = 0;
	FILE *file_open;
	size_t buffer_size = 0;

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
		start_op(stack, line_number);
		state = 1;

		if (state == 1)
			continue;
		fclose(file_open);
		exit(EXIT_FAILURE);
	}
}
