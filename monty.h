#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
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

extern stack_t *head;

typedef void(*op_func)(stack_t **, unsigned int);


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


/* Linked List Funtions */
stack_t *make_node(int n);
void free_all_nodes(void);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);
/* File Operation Functions */
void file_open(char *filename);
void file_read(FILE *file_des);
int tok_line(char *buffer, int line_num, int format);
void match_func(char *opcode, char *value, int line_num, int format);
void _exec(op_func func, char *opc, char *val, unsigned int line_n, int format);

/* Opcode functions */
void push(stack_t **node, unsigned int ln);
void pall(stack_t **node, unsigned int ln);
void pint(stack_t **node, unsigned int ln);
void pop(stack_t **node, unsigned int ln);
void _nop(stack_t **node, unsigned int ln);
void swap(stack_t **node, unsigned int ln);
void add(stack_t **node, unsigned int ln);
void sub(stack_t **node, unsigned int ln);
void _div(stack_t **node, unsigned int ln);
void _mul(stack_t **node, unsigned int ln);
void _mod(stack_t **node, unsigned int ln);
void _pchar(stack_t **node, unsigned int ln);
void _pstr(stack_t **node, unsigned int ln);
void rotl(stack_t **node, unsigned int ln);
void rotr(stack_t **node, unsigned int ln);

#endif
