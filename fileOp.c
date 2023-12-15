#include "monty.h"

/**
 * file_open - opens a file
 * @filename: the file namepath
 * Return: Nothing
 */

void file_open(char *filename)
{
	globals->fp = fopen(filename, "r");

	if (filename == NULL || globals->fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	file_read(globals->fp);
	fclose(globals->fp);
}

/**
 * file_read - reads a file
 * @file_des: pointer to a file descriptor
 * Return: Nothing
 */

void file_read(FILE *file_des)
{
	int format = 0;
	size_t len = 0;
	int ret;

	globals->ln = 1;
	ret = getline(&(globals->buf), &len, file_des);

	while (ret != -1)
	{
		format = tok_line(globals->buf, globals->ln, format);
		globals->ln++;
		ret = getline(&(globals->buf), &len, file_des);
	}
	free(globals->buf);
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
		if (globals->len != 0)
			free_all_nodes();
		exit(EXIT_FAILURE);
	}

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
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", _nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
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
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * help_exec - _exec became too long, so this will do some sub routine for it
 * @opc: ...
 * @val: ...
 * @line_n: ...
 * @format: ...
 *
 * Return: 1 if it executed, 0 if it didnt
 */
int help_exec(char *opc, char *val, unsigned int line_n, int format)
{
	stack_t *node;
	char *val_rep = val;
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
			free(globals->buf);
			fclose(globals->fp);
			if (globals->len != 0)
				free_all_nodes();
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			exit(EXIT_FAILURE);
		}
		for ( ; *val != '\0'; val++)
		{
			if (!isdigit(*val))
			{
				free(globals->buf);
				fclose(globals->fp);
				if (globals->len != 0)
					free_all_nodes();
				fprintf(stderr, "L%d: usage: push integer\n", line_n);
				exit(EXIT_FAILURE);
			}
		}
		node = make_node(atoi(val_rep) * flag);
		if (format == 0)
			add_to_stack(&node, line_n);
		if (format == 1)
			add_to_queue(&node, line_n);
		return (1);
	}
	return (0);
}
