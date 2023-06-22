#include "monty.h"
/**
 * _free_stack - Free the stack
 * @h: pointer to the head of the stack
 *
 * Return: returns nothing
 */
void _free_stack(stack_t *h)
{
	if (h != NULL)
	{
		while (h->next)
		{
			h = h->next;
			free(h->prev);
		}
		free(h);
		h = NULL;
	}
}
/**
 * _free - free string
 * @h: pointer to a pointer to strings
 *
 * Return: returns nothing
 */
void _free(char **h)
{
	while (*h)
	{
		free(*h);
		h++;
	}
}
/**
 * exit_msg2 - handles error messages for operations
 * @op: operation with error
 * @line_number: line with the error
 *
 * Return: nothing
 */
void exit_msg2(char *op, int liNum)
{
	if (strcmp(op, "push") == 0)
	{
		dprintf(2, "L%d: usage: %s integer\n", liNum, op);
		exit(EXIT_FAILURE);
	}

	else if (strcmp(op, "pint") == 0)
	{
		dprintf(2, "L%d: can't %s, stack empty\n", liNum, op);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(op, "pop") == 0)
	{
		dprintf(2, "L%d: can't %s an empty stack\n", liNum, op);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(op, "pchar") == 0)
	{
		dprintf(2, "L%d: can't %s value out of range\n", liNum, op);
		exit(EXIT_FAILURE);
	}
	else
	{
		dprintf(2, "L%d: can't %s stack too short\n", liNum, op);
		exit(EXIT_FAILURE);
	}
}
