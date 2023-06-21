#include "monty.h"
/**
 * push - adds a new item to the stack
 * @h: pointer to pointer of the head node
 * @line_number: new item to be add
 *
 * Return: returns nothing
 */
void push(stack_t **h, unsigned int line_number)
{
	stack_t *newNode;
	stack_t *ptr;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
		exit_msg("malloc", 92);

	newNode->n = line_number;

	if (*h != NULL)
	{
		ptr = *h;
		newNode->next = ptr;
		newNode->prev = NULL;
		ptr->prev = newNode;
		*h = newNode;
		ptr = NULL;

		return;
	}
	newNode->prev = NULL;
	newNode->next = NULL;
	*h = newNode;

	return;
}
/**
 * pall - prints all the item of the stack
 * @h: pointer to a pointer of the head node
 * @line_number: item to be printed
 *
 * Return: return nothing
 */
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

       	if (*h != NULL)
	{
		ptr = *h;
		while (ptr)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
	return;
}
