#include "monty.h"
/**
 * _free_stack - Free the stack
 * @h: pointer to the head of the stack
 *
 * Return: returns nothing
 */
void _free_stack(stack_t *h)
{
	while (h->next)
	{
		h = h->next;
		free(h->prev);
	}
	free(h);
	h = NULL;
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
