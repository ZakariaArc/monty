#include "monty.h"
#include <stdio.h>
/**
 * main - entry point of the program
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL; 
	int arg;
	char opcode[100];
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
	while (fscanf(file, "%99s", opcode) != EOF)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &arg) != 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				return (EXIT_FAILURE);
			}
			push(&stack, arg);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", 
				line_number, opcode);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
