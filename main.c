#include "monty.h"

int main(int argc, char **argv)
{
	char *user_buffer = NULL;
	FILE *file_open;
	size_t bufer_size = 0;

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
		printf("%s\n", user_buffer);
	}

	return (1);
}
