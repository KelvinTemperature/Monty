#include "monty.h"

/**
 * file_open - opens a file
 * @filename: the file namepath
 * Return: Nothing
 */

void file_open(char *filename)
{
	FILE *file_des = fopen(filename, "r");

	if (filename == NULL || file_des == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", filename);

	file_read(file_des);
	fclose(file_des);
}

/**
 * file_read - reads a file
 * @file_des: pointer to a file descriptor
 * Return: Nothing
 */

void file_read(File *file_des)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, file_des) != -1; line_num++)
	{
		format = tok_line(buffer, line_num, format);
	}
	free(buffer);
}

/**
 * tok_line - Separates each line into tokens to determine
 * function to call
 * @buffer: line from file
 * @line_num: line number
 * @format: storage format, 0 for stack 1 for queue
 * Return: 0 for stack and 1 for queue
 */

void tok_line(char *buffer, int line_num, int format)
{
	char *opcode, *in_val;
	const char *delim = "\n ";

	if (buffer == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	in_val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	match_func(opcode, in_val, line_num, format);

	return (format);
}

/**
 * match_func - match opcode with function to call them
 * @opcode: operatin code
 * @value: inputed value
 * @line_num: line number
 * @format: 0 for stack, 1 for queue
 */
void match_func(char *opcode, char *value, int line_num, int format)
{
	int i, flag;

	instruction_t funct_list[] = {
		{"push", },
		{"pall", },
		{"pint", },
		{"pop", },
		{"nop", },
		{"swap", },
		{"add", },
		{"sub", },
		{"div", },
		{"mul", },
		{"mod", },
		{"pchar", },
		{"pstr", },
		{"rotl", },
		{"rotr", },
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flage = 1, i = 0; funct_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, funct_list[i].opcode) == 0)
		{
			exec(func_list[i].f, opcode, value, line_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
}

/**
 * exec - executes the function called
 * @func: function to execute
 * @opc: opcode
 * @val: value
 * @line_n: Line number
 * @format: 0 for stack, 1 for queue
 */
void exec(op_func func, char *opc, char *val, int line_n, int format)
{
	stack_t *node;
	int i, flag = 1;

	if (strcmp(opc, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			fprintf(stderr, "L%d: usage: push integer\n", line_n);

		while (*val != '\0')
		{
			if (!isdigit(*val))
				fprintf(stderr, "L%d: usage: push integer\n", line_n);
			val++;
		}
		node = make_node(atoi(val) * flag);
		if (format == 0)
			func(&node, line_n);
		if (format == 1)
			add_to_queue(&node, line_n);
	}
	else
		func(&head, line_n);
}
