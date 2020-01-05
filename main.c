#include "monty.h"
void __RETURN__(char *string, char *str, char *str1);
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
	int state = 0;
	unsigned int i = 0, num_line = 0;
	stack_t *stack = NULL;

	instruction_t funcs[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop}, {"NULL", NULL}
	};

	if (argc != 2)
		__RETURN__("USAGE: monty file\n", "", "");

	file_open = fopen(argv[argc - 1], "r");
	if (file_open == NULL)
		__RETURN__("Error: Can't open file %s\n", argv[argc -1], "");

	while (getline(&user_buffer, &bufer_size, file_open) > 0)
	{
		line = user_buffer, num_line++;
		input[0] = strtok(line, delim);
		input[1] = strtok(NULL, delim);
		i = 0;
		while (funcs[i].opcode != NULL)
		{
			if (strcmp(funcs[i].opcode, input[0]) == 0)
			{
				funcs[i].f(&stack, num_line);
				state = 1;
				break;
			} i++;
		}
		if (state == 1)
			continue;
		exit(EXIT_FAILURE);
	} freeStack(&stack), fclose(file_open);
	return (EXIT_SUCCESS);
}

void __RETURN__(char *string, char *str, char *str1)
{
        fprintf(stderr, string, str, str1);
        exit(EXIT_FAILURE);
}
