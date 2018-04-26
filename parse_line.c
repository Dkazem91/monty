#include "monty.h"

/**
 * parse_line - parses through a line and returns the proper instruction
 * @line: the line
 *
 * Return: a pointer to the proper instruction
 */
instruction_t *parse_line(char *line)
{
	char *opcode;
	instruction_t *instruction;

	opcode = get_opcode(line);
	instruction = malloc(sizeof(*instruction));
	if (instruction == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	instruction->opcode = opcode;
	instruction->f = NULL;

	/* opcode control statements */

	if (instruction->opcode)
	{
		if (strcmp(instruction->opcode, "push") == 0)
			instruction->f = push;
		if (strcmp(instruction->opcode, "pall") == 0)
			instruction->f = pall;
		if (strcmp(instruction->opcode, "pint") == 0)
			instruction->f = pint;
		if (strcmp(instruction->opcode, "pop") == 0)
			instruction->f = pop;
		if (strcmp(instruction->opcode, "swap") == 0)
			instruction->f = swap;
		if (strcmp(instruction->opcode, "add") == 0)
			instruction->f = add;
		if (strcmp(instruction->opcode, "nop") == 0)
			instruction->f = nop;
		if (strcmp(instruction->opcode, "sub") == 0)
			instruction->f = sub;
		if (strcmp(instruction->opcode, "div") == 0)
			instruction->f = divide;
		if (strcmp(instruction->opcode, "mul") == 0)
			instruction->f = multiply;
		if (strcmp(instruction->opcode, "mod") == 0)
			instruction->f = moddy;
		if (strcmp(instruction->opcode, "pchar") == 0)
			instruction->f = pchar;
		if (strcmp(instruction->opcode, "pstr") == 0)
			instruction->f = pstr;
		if (strcmp(instruction->opcode, "rotl") == 0)
			instruction->f = rotl;
		if (strcmp(instruction->opcode, "rotr") == 0)
			instruction->f = rotr;
		if (strcmp(instruction->opcode, "stack") == 0)
			instruction->f = stack;
		if (strcmp(instruction->opcode, "queue") == 0)
			instruction->f = queue;
	}

	return (instruction);



}
