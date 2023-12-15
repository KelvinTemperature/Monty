#include "monty.h"

/**
 * _nop - it does nothing
 * @node: new node
 * @ln: line number
 */

void _nop(stack_t **node, unsigned int ln)
{
	(void)node;
	(void)ln;
}

/**
 * _mul - multiplies the top two elements
 * @node: top
 * @ln: line number
 */
void _mul(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;
	stack_t *tos;

	if (globals->len < 2)
	{

		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;

	tos = temp;
	temp = temp->prev;
	temp->n *= tos->n;
	temp->next = NULL;
	free(tos);

	globals->len -= 1;
	ln += 1;
}

/**
 * _mod - evaluates the modulus of the top two elements
 * @node: top
 * @ln: line number
 */
void _mod(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;
	stack_t *tos;

	if (globals->len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;

	tos = temp;
	temp = temp->prev;
	temp->n %= tos->n;
	temp->next = NULL;
	free(tos);

	globals->len -= 1;
	ln += 1;
}

/**
 * _pchar - prints the char at the top of stack
 * @node: Top of stack
 * @ln: line number
 */
void _pchar(stack_t **node, unsigned int ln)
{
	int num;

	if (node == NULL || *node == NULL || globals->len < 1)
	{
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	num = (*node)->n;
	if (num < 0 || num > 127)
	{
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();
		fprintf(stderr, "L%d: can't pchar, value of range\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", num);

	ln += 1;
}

/**
 * _pstr - prints string from the top of stack
 * @node: top of stack
 * @ln: line number
 */
void _pstr(stack_t **node, unsigned int ln)
{
	int num;
	stack_t *temp;

	(void)ln;
	if (node == NULL || *node == NULL || globals->len < 1)
	{
		printf("\n");
		return;
	}
	temp = *node;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp != NULL)
	{
		num = temp->n;
		if (num <= 0 || num > 127)
		{
			break;
		}
		printf("%c", num);

		temp = temp->prev;
	}
	printf("\n");
}
