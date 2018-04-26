#include "monty.h"
/**
 * rotl - rotates to the left
 * @stack: monty stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int lastVal;

	UNUSED(line_number);
	tmp = *stack;
	while (tmp != NULL)
	{
		if(tmp->prev)
			tmp->n = tmp->prev->n;
		if(!tmp->next)
			lastVal = tmp->n;
		tmp = tmp->next;
	}
	if((*stack))
		(*stack)->n = lastVal;
}
