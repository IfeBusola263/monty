#include "monty.h"
#include <stdio.h>
/**
 * exit_msg - handles error messages
 * @cmd: program name
 * @pos: indicates which message to trigger
 *
 * Return: returns nothing
 */
void exit_msg(char *cmd, int pos)
{
	switch (pos)
	{
		case 90:
			dprintf(2, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
			break;
		case 91:
			dprintf(2, "Error: Can't open file %s\n", cmd);
			exit(EXIT_FAILURE);
			break;
		case 92:
			dprintf(2, "Error: %s failed\n", cmd);
			_free_stack(number.headstack);
			_free(number.readline);
			exit(EXIT_FAILURE);
			break;
		default:
			dprintf(2, "L%d: unknown instruction %s\n", pos, cmd);
			_free_stack(number.headstack);
			_free(number.readline);
			exit(EXIT_FAILURE);
	}
}
/**
 * buff_fill - resets an array of strings to NULL
 * @buff: empty buffer
 * @size: size of the array
 *
 * Return: returns nothing
 */
void buff_fill(char **buff, int size)
{
	int i;

	for (i = 0; i < size; i++)
		buff[i] = NULL;
}
/**
 * _readline - reads all the lines of a file into a buffer
 * @n: new size of buffer, if buff is realloced
 * @buff: buff to all the lines
 * @fildes: file descriptor of the file
 * @filename: program name
 *
 * Return: returns the number of lines read
 */
size_t _readline(char **buff, size_t *n, FILE *fildes, char *filename)
{
	ssize_t read = 0;
	size_t count = 0;

	while (read != -1)
	{
		read = getline(buff, n, fildes);
		if (read == -1 && count == 0)
		{
			_free(number.readline);
			fclose(fildes);
			exit_msg(filename, 91);
		}
		if (read != -1)
		{
			(*buff)[read - 1] = '\0';
			buff++;
			count++;
		}
	}
	free(*buff);
	(*buff) = NULL;
	return (count);
}
/**
 * parser - splits the line into tokens to be treated
 * @lines: an arrary of strings from the file read from
 * @parse: array containing the parsed string
 * @h: is the head of linked list
 * Return: returns nothing
 */
void parser(char **lines, char **parse, stack_t **h)
{
	int i, j = 0;
	char *token;

	for (i = 0; lines[i]; i++)
	{
		token = strtok(lines[i], " ");
		while (token)
		{
			parse[j] = token;
			token = strtok(NULL, " ");
			j++;
		}
		if (stack_operations(parse, h, i + 1) != 1)
			exit_msg(parse[0], i + j);

		buff_fill(parse, j);
		j = 0;
	}
}
/**
 * stack_operations - put instructions on the stack
 * @tk_line: is the pointer to the tokenized string
 * @head: is the head of the linked list
 * @line_number: line number of instruction
 *
 *Return: 1 or 0
 */
size_t stack_operations(char **tk_line, stack_t **head, int line_number)
{
	unsigned int i, len;
	instruction_t array[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"sub", sub}, {"div", divy},
		{"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr},
	};

	if (tk_line[0] == NULL)
		return (1);

	len = sizeof(array) / sizeof(array[0]);
	for (i = 0; i < len; i++)
	{
		if (tk_line[0][0] == '#' || strcmp(tk_line[0], "nop") == 0)
			return (1);
		if (strcmp(array[i].opcode, tk_line[0]) == 0)
		{
			if (strcmp(tk_line[0], "push") == 0)
			{
				if (!tk_line[1] || check_arg(tk_line[1]) == 0)
				{
					exit_msg2(tk_line[0], line_number);
				}
				number.num = atoi(tk_line[1]);
				array[i].f(head, line_number);
				return (1);
			}

			array[i].f(head, line_number);
			return (1);
		}
	}

	return (0);
}
