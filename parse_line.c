#include "monty.h"

instruction_t *parse_line(char *line)
{
	char *opcode;
	instruction_t *instruction;

	opcode = get_opcode(line);
	instruction = malloc(sizeof(*instruction));
	if (instruction == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	instruction->opcode = opcode;
	instruction->f = NULL;

	/* opcode control statements */
	if (strcmp(instruction->opcode, "push") == 0)
		instruction->f = push;



}
