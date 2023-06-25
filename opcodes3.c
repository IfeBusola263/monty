#include "monty.h"

/**
 * pchar - prints ascii character of numeric argument
 * on top of the stack
 * @stack: is the pointer to stack_t list
 * @line_number: is the argument to opcodes
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int a;

	if (*stack == NULL)
	{
		exit_msg2("pchar", line_number);
	}
	if ((*stack)->n < 0 || (*stack)->n > 126)
	{
		exit_msg2("pchar2", line_number);
	}

	a = (*stack)->n;

	if ((a >= 0 || a <= 126))
	{
		putchar(a);
	}
	putchar('\n');
}

/**
 * pstr - prints ascii character for each number on the stack
 * @stack: is pointer to stack_t list head
 * @line_number: is the opcodes argument
 * Return: nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	int a;
	stack_t *tmp;

	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;

	while (tmp != NULL)
	{
		a = tmp->n;
		if (a <= 0 || a > 127)
		{
			break;
		}
		putchar(a);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * rotl - rotates the top to the bottom
 * @stack: pointer to the beginning of stack_t list
 * @line_number: is the arguments to the opcodes
 * Return: nothing
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *tail_stack = NULL, *new_stack = NULL;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	tmp = *stack;
	new_stack = (*stack)->next;
	tail_stack = *stack;

	while (tail_stack->next != NULL)
	{
		tail_stack = tail_stack->next;
	}

	*stack = new_stack;
	new_stack->prev = NULL;
	tail_stack->next = tmp;
	tmp->prev = tail_stack;
	tmp->next = NULL;
	tmp = NULL;
	new_stack = NULL;
	tail_stack = NULL;
}

/**
 * rotr - reverses the stack_t list elements
 * @stack: is pointer to the beginning of the list
 * @line_number: contains arguments for the opcode
 * Return: nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *cur = NULL;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	tmp = *stack;
	cur = tmp->next;
	tmp->prev = cur;
	tmp->next = NULL;

	while (cur != NULL)
	{
		cur->prev = cur->next;
		cur->next = tmp;
		tmp = cur;
		cur = cur->prev;
	}
	*stack = tmp;
	tmp = NULL;
}
