#include "monty.h"
/**
 * process_instruction - it process a single instruction
 * @file: the file pointer
 * @stack: the stack
 * @line_number: the current line number
 * Return: 0 if successful, -1 otherwise
 */

int process_instruction(FILE *file, stack_t **stack, int *line_number)
{
	char opcode[100];
	int arg;

	if (fscanf(file, "%99s", opcode) == EOF)
		return (-1);
	if (strcmp(opcode, "push") == 0)
	{
		if (fscanf(file, "%d", &arg) != 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", *line_number);
			return (-1);
		}
		push(stack, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, *line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", *line_number, opcode);
		return (-1);
	}
	return (0);
}

/**
 * main - the entry point of the program
 * @argc: the number of command-line arguments
 * @argv: an array containing the command-line arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (process_instruction(file, &stack, &line_number) == 0)
		line_number++;
	fclose(file);
	return (0);
}
