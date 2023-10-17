#include "monty.h"
/**
 * push - it pushes an element to the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the file
 * @n: the integer value to push
 */

void push(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}
	*stack = new_node;
}
