#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - the monty code interpreter
 * @argc: the number of arguments
 * @argv: the monty file location
 * Return: 0 (success)
*/

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char content[1000];
	FILE *file;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(content, sizeof(content), file) != NULL)
	{
		bus.content = content;
		counter++;
		execute(content, &stack, counter, file);
	}
	stack_free(stack);
	fclose(file);
	return (0);
}
