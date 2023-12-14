#include "monty.h"

/* contains the opcode functions to perform operations */
/**
 * push - pushes a node to top of stack (TOS)
 * node: node containing element to push
 * Description: you have handeled the line number
 * in the parsing already and also youi have converted
 * the value to int already so i need not to handle them
 * inside this function.
 */
void push(stack_t **node)
{
	stack_t *ptr = *node;
	stack_t *temp = head;

	if (head == NULL)
	{
		head = ptr;
		head->prev = NULL;
		head->next = NULL;
		return;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = ptr;
	ptr->prev = temp;
	ptr->next = NULL;
}
