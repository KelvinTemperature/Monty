#include "monty.h"

/**
 * push - pushes node to top of stack (TOS)
 * @node: node to push
 * @ln: line number
 * Description: The integer checking and conversion
 * should be done by the calling function, not this function
 */
void push(stack_t **node, unsigned int ln)
{
	stack_t *temp;

	if (globals->head == NULL)
	{
		globals->head = *node;
		globals->head->prev = NULL;
		globals->head->next = NULL;

		ln += 1;
		return;
	}

	temp = globals->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *node;
	(*node)->prev = temp;
	(*node)->next = NULL;
	ln += 1;
}


/**
 * pall - prints stack
 * @node: node, preferable TOP OF STACK, for speed sake
 * @ln: line number
 */
void pall(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;

	if (globals->tail == NULL)
	{
		if (globals->head == NULL)
			return;
		printf("%d\n", globals->head->n);
	}
	else
	{
		temp = globals->tail;
		printf("%d\n", temp->n);
		while (temp->prev != NULL)
		{
			temp = temp->prev;
			printf("%d\n", temp->n);
		}
	}
	ln += 1;
}

/**
 * pint - peek into top of stack
 * @node: node, preferable TOP OF STACK, for speed sake
 * @ln: line number
 */
void pint(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;

	if (globals->len < 1)
	{
		fclose(globals->fp);
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		free(globals->buf);
		exit(EXIT_FAILURE);
	}
	if (globals->head == NULL && globals->len > 1)
	{
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
		temp = temp->next;

	printf("%d\n", temp->n);

	ln += 1;
}


/**
 * pop - deletes top of stack
 * @node: node, preferable TOP OF STACK, for speed sake
 * @ln: line number
 */
void pop(stack_t **node, unsigned int ln)
{
	stack_t *temp, *store;

	if (globals->len == 0)
	{
		free(globals->buf);
		fclose(globals->fp);
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	temp = *node;
	if (temp->next != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
	}

	globals->len -= 1;
	store = temp->prev;

	if (globals->len > 0)
		store->next = NULL;
	globals->tail = store;
	free(temp);
	ln += 1;
}

/**
 * swap - swaps TOS with TOS - 1
 * @node: node, preferable TOP OF STACK, for speed sake
 * @ln: line number
 */
void swap(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;
	stack_t *tos = globals->tail;


	if (globals->len < 2)
	{
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
		temp = temp->next;
	temp = temp->prev;
	tos->next = tos->prev;
	tos->prev = temp->prev;
	temp->prev->next = tos;
	temp->prev = tos;
	temp->next = NULL;

	globals->tail = temp;
	ln += 1;
}
