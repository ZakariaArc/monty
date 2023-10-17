#include "monty.h"
/**
 * pall - prints all the values on the stack
 * @stack: the pointer to the stack
 * @line_number: the line number in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
