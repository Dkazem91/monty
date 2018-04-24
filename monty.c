#include "monty.h"

/**
 * main - main function for monty
 * @argc: argument count
 * @argv: array of argument strings
 *
 * Return: exit code
 */
int main(int argc, char **argv)
{
	FILE *file_in
	unsigned int line_number;
	char line[LINE_MAX];

	/* check for proper number of arguments */
	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open file */
	file_in = fopen(argv[1], "r");
	if (file_in == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

}
