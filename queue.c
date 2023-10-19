#include "monty.h"
/**
 * queue - it prints the top
 * @head: a pointer to the head of the stack
 * @counter: the current line number
 * Return: nothing
*/

void queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * queueadd - it add node to the tail stack
 * @n: the new value
 * @head: a pointer to the head of the stack
 * Return: nothing
*/

void queueadd(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
