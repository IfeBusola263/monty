#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#define _GNU_SOURCE
#define BUFFER 1024
#define PARSE 20
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

typedef struct mem_s
{
	int num;
} mem_t;
extern mem_t number;
void exit_msg(char *cmd, int pos);
void buff_fill(char **buff, int size);
size_t _readline(char **buff, size_t *n, FILE *fildes, char *filename);
void parser(char **lines, char **parse, stack_t **h);
size_t stack_operations(char **tk_line, stack_t **head, int line_number);
void push(stack_t **h, unsigned int line_number);
void pall(stack_t **h, unsigned int line_number);
void _free_stack(stack_t *h);
void _free(char **h);

#endif /* MONTY_H */
