#include "monty.h"
/**
 * rotr - rotates to the right
 * @stack: monty stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int lastVal;

	UNUSED(line_number);
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	if (tmp)
		lastVal = tmp->n;
	while (tmp->prev != NULL)
	{
		tmp->n = tmp->prev->n;
		tmp = tmp->prev;
	}
	if (tmp)
		tmp->n = lastVal;
}
