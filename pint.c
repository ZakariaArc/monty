#include "monty.h"
/**
 * pint - it prints the top
 * @head: a pointer to the head of the stack
 * @counter: the current line number
 * Return: nothing
*/

void pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
