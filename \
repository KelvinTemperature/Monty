#include "main.h"


/**
 * rotr - rotates list;
 * @node: any node
 * @ln: line number
 */
void rotr(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;
	stack_t *swap;

	if (*node == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = head;
	head->prev = temp;
	temp = head->next;
	head->next = NULL;

	swap = head;
	head = temp;
	head->prev = NULL;

	ln += 1;
}


/**
 * rot1 - rotates list;
 * @node: any node
 * @ln: line number
 */
void rot1(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;
	stack_t *swap;

	if (*node == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = head;
	temp->prev->next = NULL;
	temp->prev = NULL;

	swap = head;
	head = temp;
	temp = swap;

	ln += 1;
}
