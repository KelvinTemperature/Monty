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
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	file_read(file_des);
	fclose(file_des);
}

/**
 * file_read - reads a file
 * @file_des: pointer to a file descriptor
 * Return: Nothing
 */

void file_read(FILE *file_des)
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

int tok_line(char *buffer, int line_num, int format)
{
	char *opcode, *in_val;
	const char *delim = "\n\t ";

	if (buffer == NULL)
	{
		exit(EXIT_FAILURE);
	}

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
	{
 		return (format);
	}

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
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		/*{"nop", _nop},*/
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		/*{"mul", _mul},*/
		/*{"mod", _mod},*/
		/*{"pchar", _pchar},*/
		/*{"pstr", _pstr},*/
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; funct_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, funct_list[i].opcode) == 0)
		{
			_exec(funct_list[i].f, opcode, value, line_num, format);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * _exec - executes the function called
 * @func: function to execute
 * @opc: opcode
 * @val: value
 * @line_n: Line number
 * @format: 0 for stack, 1 for queue
 */
void _exec(op_func func, char *opc, char *val, unsigned int line_n, int format)
{
	char *val_rep = val;
	stack_t *node;
	int flag = 1;

	if (strcmp(opc, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			exit(EXIT_FAILURE);
		}

		while (*val != '\0')
		{
			if (!isdigit(*val))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_n);
				exit(EXIT_FAILURE);
			}
			val++;
		}
		node = make_node(atoi(val_rep) * flag);
		if (format == 0)
			func(&node, line_n);
		if (format == 1)
			add_to_queue(&node, line_n);
	}
	else
		func(&head, line_n);
}
