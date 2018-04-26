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
	stack_t *new, *tmp;
	char *push_arg = strtok(NULL, "\n \t");
	int pVal;
	/*if push, tests if the push_arg was valid or not */
	if (!is_int(push_arg))
	{
		fprintf(stdout, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}


	pVal = atoi(push_arg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = pVal;
	new->prev = NULL;
	new->next = NULL;
	/** checks if stack is empty **/
	if ((*stack) == NULL)
		*stack = new;
	else if (SQ)
	{
		/** puts new node on top if not empty **/
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
	else
	{
		/**puts new node on the bottom **/
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}

}
