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

	(void)line_number;
	newNode->n = number.num;

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
	stack_t *tmp = *stack;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else if (*stack != NULL && (*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
		exit_msg2("pop", line_number);
}

/**
 * pint - print the element on top of the stack
 * @stack: is the pointer to the top of the stack
 * @line_number: is both line no and the argument on each line
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top != NULL)
	{
		printf("%d\n", top->n);
	}
	else
		exit_msg2("pint", line_number);
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
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		exit_msg2("swap", line_number);
	}
	tmp = *stack;
	current = (*stack)->next;

	n = tmp->n;
	tmp->n = current->n;
	current->n = n;
}
