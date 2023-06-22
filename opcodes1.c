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
}
/**
 * pop - remove element at the top of a stack
 * @stack: is the pointer to the top of the stack
 * @line_number: is both the line no and arguments on the line
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *previous;

	if (*stack == NULL)
	{
		/*print error msg*/
	}

	(*stack) = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pint - print the element on top of the stack
 * @stack: is the pointer to the top of the stack
 * @line_number: is both line no and the argument on each line
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		/*print error msg*/
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap - exchanges the element between the two top element
 * @stack: is pointer to stack top
 * @line_number: contains both line no and argument
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *current;
	int i = 0, n;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		/*print error msg*/
	}
	tmp = *stack;
	current = (*stack)->next;

	n = tmp->n;
	tmp->n = current->n;
	current->n = n;
}
