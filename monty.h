#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#define _GNU_SOURCE
#define BUFFER 1024
#define PARSE 100
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
/**
 * struct mem_s - global variable representation
 * @num: integer member
 * @bottom: stack tail
 * @headstack: holds address of the headstack
 * @readline: holds the address of buffer of lines
 *
 * Description: Global variable structure
 */
typedef struct mem_s
{
	int num;
	stack_t *bottom;
	stack_t **headstack;
	char **readline;
} mem_t;
extern mem_t number;
void exit_msg(char *cmd, int pos);
void buff_fill(char **buff, int size);
size_t _readline(char **buff, size_t *n, FILE *fildes, char *filename);
void parser(char **lines, char **parse, stack_t **h);
size_t stack_operations(char **tk_line, stack_t **head, int line_number);
void push(stack_t **h, unsigned int line_number);
void pall(stack_t **h, unsigned int line_number);
void _free_stack(stack_t **h);
void _free(char **h);
int check_arg(char *arg);
void exit_msg2(char *op, int liNum);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void divy(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsig

#endif /* MONTY_H */
