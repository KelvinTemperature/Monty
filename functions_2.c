#include "monty.h"


/**
 * add - adds  tos - 1
 * @node: any node, preferably top os stack
 * @ln: line number
 */
void add(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;
	stack_t *tos;

	if (globals->len < 2)
	{
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;

	tos = temp;
	temp = temp->prev;
	temp->n += tos->n;
	temp->next = NULL;
	globals->tail = temp;
	free(tos);

	globals->len -= 1;
	ln += 1;
}
/**
 * sub - sutracts tos trom tos - 1
 * @node: any node, preferably top os stack
 * @ln: line number
 */
void sub(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;
	stack_t *tos;

	if (globals->len < 2)
	{
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	tos = temp;
	temp = temp->prev;
	temp->n -= tos->n;
	temp->next = NULL;
	globals->tail = temp;
	free(tos);

	globals->len -= 1;
	ln += 1;
}

/**
 * _div - divides tos -1 by tos
 * @node: any node, preferably top os stack
 * @ln: line number
 */
void _div(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;
	stack_t *tos;

	if (globals->len < 2)
	{
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
		temp = temp->next;

	tos = temp;
	temp = temp->prev;
	if (tos->n == 0)
	{
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();
		fprintf(stderr, "L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	temp->n /= tos->n;
	temp->next = NULL;
	globals->tail = temp;
	free(tos);

	globals->len -= 1;
	ln += 1;
}
