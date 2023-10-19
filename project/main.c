#include "monty.h"

void bus_struct(bus_t *bus);

/**
 * main - the monty code interpreter
 * @argc: the number of arguments
 * @argv: the monty file location
 * Return: 0 (success)
*/

int main(int argc, char *argv[])
{
	bus_t bus = {NULL, NULL, NULL, 0};
	stack_t *stack = NULL;
	char content[150];
	FILE *file = fopen(argv[1], "r");
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	bus.file = file;
	bus_struct(&bus);
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(content, sizeof(content), file) != NULL)
	{
		bus.content = content;
		bus_struct(&bus);
		counter++;
		execute(content, &stack, counter, file);
	}
	stack_free(stack);
	fclose(file);
	return (0);
}
void bus_struct(bus_t *bus)
{
	if (bus->arg)
		printf("%s\n", bus->arg);
	if (bus->file)
		fprintf(stdout, "%p\n", (void*)bus->file);
	if (bus->content)
		printf("%s\n", bus->content);
	if (bus->lifi)
		printf("%d\n", bus->lifi);
}
