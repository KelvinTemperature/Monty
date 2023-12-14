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

	if (head == NULL)
	{
		head = *node;
		head->prev = NULL;
		head->next = NULL;

		ln += 1;
		return;
	}

	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		printf("temp: %d\n", temp->n);
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

	while (temp->next != NULL)
		temp = temp->next;

	printf("%d\n", temp->n);
	while (temp->prev != NULL)
	{
		temp = temp->prev;
		printf("%d\n", temp->n);
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

	if (temp == NULL || !temp->n)
	{
		fprintf(stderr, "L%d: can't pint, empty stack\n", ln);
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
	stack_t *temp;

	if (*node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	temp = *node;
	if (temp->next != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->prev->next = NULL;
		free(temp);
	}
	else
	{
		free(temp);
		*node = NULL;
	}

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
	stack_t *tos, *swap;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
		temp = temp->next;

	tos = temp;
	if (temp->prev == NULL || temp->prev->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	swap = tos->prev->prev;
	tos->prev->prev = temp;
	tos->prev->next = NULL;
	tos->next = temp->prev;
	tos->prev = swap;

	ln += 1;
}
