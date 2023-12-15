#include "monty.h"


/**
 * rotl - rotates list;
 * @node: any node
 * @ln: line number
 */
void rotl(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;

	if (temp == NULL || globals->len == 1)
		return;

	globals->tail->next = globals->head;
	globals->tail->prev->next = NULL;
	temp = globals->tail->prev;
	globals->head->prev = globals->tail;
	globals->head = globals->tail;
	globals->head->prev = NULL;
	globals->tail = temp;

	ln += 1;
}

/**
 * rotr - rotates list;
 * @node: any node
 * @ln: line number
 */
void rotr(stack_t **node, unsigned int ln)
{
	stack_t *temp = *node;

	if (temp == NULL || globals->len == 1)
		return;
	while (temp->next != NULL)
		temp = temp->next;

	globals->tail->next = globals->head;
	globals->head->prev = globals->tail;
	temp = globals->head->next;
	globals->head->next = NULL;
	temp->prev = NULL;
	globals->head = temp;
	globals->tail = globals->tail->next;

	ln += 1;
}
