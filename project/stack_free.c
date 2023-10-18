#include "monty.h"
/**
 * stack_free - it frees a doubly linked list
 * @head: a pointer to the head of the stack
*/

void stack_free(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
