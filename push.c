#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int pVal;

	UNUSED(line_number);

	pVal = atoi(push_arg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stdin, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = pVal;
	new->prev = NULL;
	new->next = NULL;
	/** checks if stack is empty **/
	if ((*stack) == NULL)
		*stack = new;
	else
	{
		/** puts new node on top if not empty **/
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}

}
