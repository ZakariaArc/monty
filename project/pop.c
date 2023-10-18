#include "monty.h"
/**
 * pop - it prints the top
 * @head: a pointer to the head of the stack
 * @counter: the current line number
 * Return: nothing
*/

void pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
