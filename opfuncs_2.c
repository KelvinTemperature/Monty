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

	if (*node == NULL || (*node)->next == NULL)
	{
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

        if (*node == NULL || (*node)->next == NULL)
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

        ln += 1;
}
