#include "main.h"


/**
 * add - adds  tos - 1
 * @node: any node, preferably top os stack
 * @ln: line number
 */
void add(stack_t **node, unsigned int ln)
{
	stack_t temp = *node;
	stack_t *tos;
	if (*node == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", ln);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;

	if (temp->prev == NULL || temp->prev->prev == NULL)
	{
		fprintf(stderr, "L%d: can;t sub, stack too short", ln)
			exit(EXIT_FAILURE);
	}

	tos = temp;
	temp = temp->prev;
	temp->n -= tos->n;
	temp->next = NULL;
	free(tos);

	ln += 1;
/**
 * sub - sutracts tos trom tos - 1
 * @node: any node, preferably top os stack
 * @ln: line number
 */
void sub(stack_t **node, unsigned int ln)
{
	stack_t temp = *node;
	stack_t *tos;
	if (*node == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", ln);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;

	if (temp->prev == NULL || temp->prev->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", ln)
			exit(EXIT_FAILURE);
	}

	tos = temp;
	temp = temp->prev;
	temp->n -= tos->n;
	temp->next = NULL;
	free(tos);

	ln += 1;
}



/**
 * _div: divides tos -1 by tos
 * @node: any node, preferably top os stack
 * @ln: line number
 */
void sub(stack_t **node, unsigned int ln)
{
	stack_t temp = *node;
	stack_t *tos;
	if (*node == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", ln);
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;

	if (temp->prev == NULL || temp->prev->prev == NULL)
	{
		fprintf(stderr, "L%d: can' div, stack too short", ln)
			exit(EXIT_FAILURE);
	}

	tos = temp;
	temp = temp->prev;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", ln);
		exit(EXIT_FAILURE);
	}
	temp->n /= tos->n;
	temp->next = NULL;
	free(tos);

	ln += 1;
