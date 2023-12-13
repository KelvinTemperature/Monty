#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void(*op_func)(stack_t **, unsigned int);

/* Linked List Funtions */
stack_t *make_node(int n);
void free_all_nodes(void);
void add_to_queue(stack_t __attribute__((unused))unsigned int);

/* File Operation Functions */
void file_open(char *filename);
void file_read(FILE *file_des);
int tok_line(char *buffer, int line_num, int format);
void match_func(char *opcode, char *value, int line_num, int format);
void exec(op_func func, char *opc, char *val, int line_n, int format);

#endif
