#include "monty.h"


/**
 * rotr - rotates list;
 * @node: any node
 * @ln: line number
 */
void rotr(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;

	if (temp == NULL || temp->next == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *node;
	(*node)->prev = temp;
	temp = temp->prev;
	temp->next->prev = NULL;
	temp->next = NULL;

	*node = temp;

	ln += 1;
}

/**
 * rotl - rotates list;
 * @node: any node
 * @ln: line number
 */
void rotl(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;

	if (temp == NULL || temp->next == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *node;
	(*node)->prev = temp;
	*node = (*node)->next;
	(*node)->prev->next = NULL;
	(*node)->prev = NULL;

	ln += 1;
}
