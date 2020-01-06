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

	unsigned int num_line = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	activate_op(&stack, num_line, argv[argc - 1]);
	freeStack(stack);
	return (0);
}
