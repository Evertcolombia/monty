#include "monty.h"
/**
 * main - entry point
 * @argc: total of arguments
 * @argv: arguments
 *
 * Return:  0  on success
 */
int main(int argc, char **argv)
{
	char *user_buffer = NULL, *line, *delim = "\n ";
	FILE *file_open;
	size_t bufer_size = 0;
	unsigned int i = 0, num_line = 0;
	stack_t *stack = NULL;

	instruction_t funcs[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint}
	};

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (0);
	}
	file_open = fopen(argv[argc - 1], "r");
	if (file_open == NULL)
	{
		printf("Error: Can't open file %s\n", argv[argc - 1]);
		return (0);
	}
	while (getline(&user_buffer, &bufer_size, file_open) > 0)
	{
		line = user_buffer, num_line++;
		input[0] = strtok(line, delim);
		input[1] = strtok(NULL, delim);

		while (i <= num_line)
		{
			if (strcmp(funcs[i].opcode, input[0]) == 0)
			{
				funcs[i].f(&stack, num_line);
				break;
			} i++;
		}
	} freeStack(&stack), fclose(file_open);
	return (1);
}
