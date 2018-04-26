#include "monty.h"
/**
 * rotl - rotates to the left
 * @stack: monty stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int firstVal;

	UNUSED(line_number);
	tmp = *stack;
	if (tmp)
		firstVal = tmp->n;
	while (tmp != NULL)
	{
		if (tmp->next)
			tmp->n = tmp->next->n;
		else
			tmp->n = firstVal;
		tmp = tmp->next;
	}
}
