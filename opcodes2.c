#include "monty.h"

/**
 * add - adds the top two stack elements
 * @stack: is the stack head pointer
 * @line_number: contains the arguments on each line
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *current;
	int a, b, sum;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		/*print error msg*/
	}
	tmp = (*stack)->next;

	a = (*stack)->n;
	b = tmp->n;
	sum = a + b;

	(*stack)->n = sum;
	current = tmp;
	tmp = tmp->next;
	(*stack)->next = tmp;
	free(current);
}

/**
 * sub - sub the stack top two elements
 * @stack: is pointer to stack top
 * @line_number: contains the opcodes arguments
 * Return: nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int a, b, result;
	stack_t *tmp, *current;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
	    /*print error msg*/
	}
	tmp = (*stack)->next;
	a = tmp->n;
	b = (*stack)->n;
	result = a - b;

	(*stack)->n = result;

	current = tmp;
	tmp = tmp->next;
	(*stack)->next = tmp;
	free(current);
}

/**
 * mod - returns the remainder of the division of stack
 * top two elements
 * @stack: is pointer to stack_t top element
 * @line_number: contains the opcodes arguments
 * Return: nothing
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *current;
	int a, b, result;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		/*print error msg*/
	}

	tmp = (*stack)->next;
	a = tmp->n;
	b = (*stack)->n;
	result = a % b;

	(*stack)->n = result;

	current = tmp;
	tmp = tmp->next;
	(*stack)->next = tmp;
	free(current);
}

/**
 * mul - multiplies the two top stack elements
 * @stack: pointer to the stack_t list
 * @line_number: is the argument to the opcodes
 * Return: nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int a, b, result;
	stack_t *tmp, *current;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		/*print error msg*/
	}

	tmp = (*stack)->next;
	a = tmp->n;
	b = (*stack)->n;
	result = a * b;

	(*stack)->n = result;

	current = tmp;
	tmp = tmp->next;
	(*stack)->next = tmp;
	free(current);
}

/**
 * divi - divides the two top stack elements
 * @stack: is pointer to stack_t list
 * @line_number: is the arguments to the opcodes
 * Return: nothing
 */

void divy(stack_t **stack, unsigned int line_number)
{
	int a, b, result;
	stack_t *tmp, *current;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		/*print error msg*/
	}

	tmp = (*stack)->next;
	a = tmp->n;
	b = (*stack)->n;
	result = a / b;

	(*stack)->n = result;

	current = tmp;
	tmp = tmp->next;
	(*stack)->next = tmp;
	free(current);
}
