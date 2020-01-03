#include "monty.h"

void __RETURN__(char *string, char *str, char *str1)
{
	fprintf(stderr, string, str, str1);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	char *user_buffer = NULL, *filename = NULL;
	FILE *file;
	size_t bufer_size = 0;

	if (argc != 2)
		__RETURN__("USAGE: monty file\n", "", "");

	filename = argv[argc - 1];
	file = fopen(filename, "r");
	if (file == NULL)
		__RETURN__("Error: Can't open file %s\n", filename, "");

	while (getline(&user_buffer, &bufer_size, file) > 0)
	{
		printf("%s\n", user_buffer);
	}

	return (1);
}
