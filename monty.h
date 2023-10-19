#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: an integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: the pointer to the Monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
 
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void queueadd(stack_t **head, int n);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void mod(stack_t **head, unsigned int counter);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void rotl(stack_t **head, unsigned int counter);
void pop(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
char *clean_line(char *content);
void pchar(stack_t **head, unsigned int counter);
void nodeadd(stack_t **head, int n);
void pall(stack_t **head, unsigned int number);
void sub(stack_t **head, unsigned int counter);
void push(stack_t **head, unsigned int number);
ssize_t getstdin(char **lineptr, int file);
void queue(stack_t **head, unsigned int counter);
void stack_free(stack_t *head);
void nop(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void pint(stack_t **head, unsigned int number);
void divi(stack_t **head, unsigned int counter);
void stack_op(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter);

#endif
