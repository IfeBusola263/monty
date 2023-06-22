#include "monty.h"
/**
 * add - adds the top two stack elements
 * @stack: is the stack head pointer
 * @line_number: contains the arguments on each line
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		exit_msg2("add", line_number);
	}
	tmp = *stack;
	*stack = (*stack)->next;

	sum = (*stack)->n +  tmp->n;

	(*stack)->n = sum;
	tmp->next = NULL;
	(*stack)->prev = NULL;
	free(tmp);
	tmp = NULL;
}

/**
 * sub - sub the stack top two elements
 * @stack: is pointer to stack top
 * @line_number: contains the opcodes arguments
 * Return: nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp = NULL;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		exit_msg2("sub", line_number);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	result = (*stack)->n - tmp->n;

	(*stack)->n = result;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	free(tmp);
	tmp = NULL:
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
		exit_msg2("mod", line_number);
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
		exit_msg2("mul", line_number);
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
 * divy - divides the two top stack elements
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
		exit_msg2("divy", line_number);
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
