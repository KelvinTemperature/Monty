#include "monty.h"


globals_t *globals;


/**
 * main - Entry function for the program
 * @ac: Argument Count
 * @av: Argument vector
 * Return: Always 0
 */

int main(int ac, char **av)
{
	globals_t all_var = GLOBAL_INIT;

	globals = &all_var;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_open(av[1]);
	free_all_nodes();

	return (0);
}
