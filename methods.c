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
	switch(pos)
	{
		case 90:
			dprintf(2 , "USAGE: monty file\n");
			exit(EXIT_FAILURE);
			break;
		case 91:
			dprintf(2, "Error: Can't open file %s\n", cmd);
			exit(EXIT_FAILURE);
			break;
		case 92:
			dprintf(2, "Error: %s failed\n", cmd);
			exit(EXIT_FAILURE);
			break;
		default:
			dprintf(2, "L%d: unknown instruction %s\n", pos, cmd);
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
	ssize_t read;
	size_t count;

	count = 0;
	while (read != -1)
	{
		read = getline(buff, n, fildes);
		if (read == -1 && count == 0)
			exit_msg(filename, 91);

		(*buff)[read - 1] = '\0';
		buff++;
		count++;
	}
	return (count);
}
/**
 * parser - splits the line into tokens to be treated
 * @lines: an arrary of strings from the file read from
 * @parse: array containing the parsed string
 *
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
		if (stack_operations(parse, h) != 1)
			exit_msg(parse[0], atoi(parse[1]));

		/* buff_fill(parse, PARSE); */
		j = 0;
	}
	/**
	 * for (i = 0; parse[i] != NULL; i++)
	 * printf("%s\n", parse[i]);
	 * printf("\n-------in----parser-------------\n");
	 */
}
size_t stack_operations(char **tk_line, stack_t **head)
{
	unsigned int i, len;
	instruction_t array[] = {
		{"push", push},
		{"pall", pall},
	};

	len = sizeof(array)/ sizeof(array[0]);
	for (i = 0; tk_line[i]; i++)
		printf("%s\n", tk_line[i]);

	/* printf("\n--------in---stack--operation-----------\n"); */
	for (i = 0; i < len; i++)
	{
      		if (strcmp(array[i].opcode, tk_line[0]) == 0)
		{
		      	array[i].f(head, (unsigned int)atoi(tk_line[1]));
			return (1);
		}

	}

	return (0);
}
