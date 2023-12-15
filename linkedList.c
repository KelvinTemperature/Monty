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
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(globals->buf);
		fclose(globals->fp);

		if (globals->len != 0)
			free_all_nodes();
		exit(EXIT_FAILURE);
	}
	if (globals->len < 1)
	{
		globals->head = new_node;
		globals->head->next = NULL;
		globals->head->prev = NULL;
		globals->tail = globals->head;
		globals->len += 1;
		globals->head->n = n;
	}
	else
	{
		globals->len += 1;
		new_node->next = NULL;
		new_node->prev = NULL;
		new_node->n = n;
	}

	return (new_node);
}

/**
 * free_all_nodes - frees all nodes in stack
 */
void free_all_nodes(void)
{
	stack_t *temp;

	if (globals->head == NULL || globals->len < 1)
		return;
	while (globals->head != NULL)
	{
		temp = globals->head;
		globals->head = globals->head->next;
		free(temp);
	}
}


/**
 * add_to_stack - adds a node to the stack
 * @new_node: pointer to new node
 * @ln: line number of the opcode
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
	{
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();

		exit(EXIT_FAILURE);
	}
	if (globals->len == 1)
		return;
	if (globals->head == NULL)
	{
		globals->head = *new_node;
		globals->head->prev = NULL;
		globals->head->next = globals->tail;
		return;
	}
	temp = globals->head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_node;
	globals->tail = *new_node;
	globals->tail->prev = temp;
	globals->tail->next = NULL;
}

/**
 * add_to_queue - adds a node to the queue
 * @new_node: pointer to new node
 * @ln: line number of the opcode
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp = *new_node;

	if (globals->len < 1)
	{
		free(globals->buf);
		fclose(globals->fp);
		if (globals->len != 0)
			free_all_nodes();

		exit(EXIT_FAILURE);
	}
	if (globals->len == 1)
		return;

	temp = globals->tail;
	while (temp->prev != NULL)
		temp = temp->prev;
	temp->prev = *new_node;
	globals->head = *new_node;
	globals->head->next = temp;
	globals->head->prev = NULL;

}
