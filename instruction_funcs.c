#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int pVal;

	UNUSED(line_number);

	pVal = atoi(push_arg);
	new = malloc(sizeof(stack_t));
	if(new == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = pVal;
	new->prev = NULL;
	new->next = NULL;
	/** checks if stack is empty **/
	if((*stack) == NULL)
		*stack = new;
	else
	{
		/** puts new node on top if not empty **/
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}

}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	UNUSED(line_number);

	tmp = *stack;
	while(tmp != NULL)
	{
		printf("%d\n",tmp->n);
		tmp = tmp->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr,"L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n",(*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if((*stack) == NULL)
	{
		fprintf(stderr,"L%d: can't pop an empty stack\n",line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
