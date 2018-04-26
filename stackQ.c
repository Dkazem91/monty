#include "monty.h"
/**
 * stack - changes to LIFO
 * @stack: monty stack
 * @line_number: line number of file
 */
void stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	SQ = 1;
}
/**
 * queue - changes to FIFO
 * @stack: monty stack
 * @line_number: line number of file
 */
void queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	SQ = 0;
}
