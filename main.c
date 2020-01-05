#include "monty.h"

int main(int argc, char **argv)
{
	char *user_buffer = NULL, /**input[2],*/ *line, *delim = "\n ";
	FILE *file_open;
	size_t bufer_size = 0;
	unsigned int i = 0;
	unsigned int num_line = 0;
	stack_t *stack = NULL; /*, *new_num = NULL;*/

	instruction_t  funcs [] = {
                {"push", f_push}
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
	printf("file was open:  %s\n", argv[argc - 1]);

	while (getline(&user_buffer, &bufer_size, file_open) > 0)
	{
		line = user_buffer;
		num_line++;

		/*while (line[i] == delim[0] || line[i] == delim[1])
		{
			printf("pasa bucle\n");
			i++;
		}*/

		input[0] = strtok(line, delim);
		input[1] = strtok(NULL, delim);
		i = 0;

		while (i <= num_line)
		{
			printf("funcs[i].opcode: %s\n", funcs[i].opcode);

			if (strcmp(funcs[i].opcode, input[0]) == 0)
			{
				printf("calling function \n");
				/*f_push(&stack, num_line);*/
				funcs[i].f(&stack, num_line);
				break;
			} i++;
		}
	} freeStack(&stack), fclose(file_open);
	printf("stack was free\n");
	return (1);
}
