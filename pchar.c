#include "monty.h"
/**
 * pchar - prints the char at a the top
 * @stack: monty stack
 * @line_number: line number to grab
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!isprint((*stack)->n))
	{
		fprintf(stdout, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
