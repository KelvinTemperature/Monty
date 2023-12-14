#include "monty.h"

/**
 * make_node - creates a node
 * @n: number to be added
 * Return: pointer to new node or NULL
 */
stack_t *make_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	printf("NEW NODE: %d\n", n);

	return (new_node);
}

/**
 * free_all_nodes - frees all nodes in stack
 */
void free_all_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
/**
 * add_to_queue - adds a node to the queue
 * @new_node: pointer to new node
 * @ln: line number of the opcode
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_node;
	(*new_node)->prev = temp;
}
