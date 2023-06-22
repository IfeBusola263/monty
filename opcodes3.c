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
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		/*print error msg*/
	}

	a = (*stack)->n;

	if (a >= 65 && a <= 90 || a >= 97 && a <= 126)
	{
		putchar(a);
	}
}

/**
 * pstr - prints ascii character for each number on the stack
 * @stack: is pointer to stack_t list head
 * @line_number: is the opcodes argument
 * Return: nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("\n");
	}

	int a;

	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		a = tmp->n;
		if (a <= 0 || a > 255)
		{
			break;
		}
		putchar(a);
		tmp = tmp->next;
	}
}
