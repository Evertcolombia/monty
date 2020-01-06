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

	unsigned int num_line = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		__RETURN__("USAGE: monty file\n", "", "");

	activate_op(&stack, num_line, argv[argc - 1]);
	freeStack(stack);
	return (EXIT_SUCCESS);
}

/**
 * __RETURN__ - return posix
 * @string: string
 * @str: param
 * @str1: param
 * Return: exit
 */
void __RETURN__(char *string, char *str, char *str1)
{
	fprintf(stderr, string, str, str1);
	exit(EXIT_FAILURE);
}
