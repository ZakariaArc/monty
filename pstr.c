#include "monty.h"
/**
 * pstr - it prints the string starting at the top of the stack,
 *        followed by a new
 * @head: a pointer to the head of the stack
 * @counter: the current line number
 * Return: nothing
*/

void pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}