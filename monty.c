#include "monty.h"

char *push_arg = NULL;

/**
 * main - main function for monty
 * @argc: argument count
 * @argv: array of argument strings
 *
 * Return: exit code
 */
int main(int argc, char **argv)
{
	FILE *file_in;
	unsigned int line_number = 0;
	char *line = NULL;
	stack_t *top = NULL;
	instruction_t *instruction = NULL;
	size_t glsize = 0;

	/* check for proper number of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open file */
	file_in = fopen(argv[1], "r");
	if (file_in == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* parse file */
	while (getline(&line, &glsize, file_in) != -1)
	{
		line_number++;
		instruction = parse_line(line);

		if (!(instruction->opcode))
		{
			free(instruction);
			if (line)
				free(line);
			line = NULL;
			continue;
		}

		/*if push, tests if the push_arg was valid or not */
		if (strcmp(instruction->opcode, "push") == 0 && !is_int(push_arg))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free(instruction);
			if (top)
				free_stack(top);
			if (line)
				free(line);
			fclose(file_in);

			exit(EXIT_FAILURE);
		}

		if (instruction->f)
			instruction->f(&top, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, instruction->opcode);
			if (line)
				free(line);
			if (top)
				free_stack(top);
			free(instruction);
			fclose(file_in);
			exit(EXIT_FAILURE);
		}

		if (line)
			free(line);
		line = NULL;
		free(instruction);
	}

	if (line)
		free(line);
	free_stack(top);
	fclose(file_in);
	return (EXIT_SUCCESS);
}
