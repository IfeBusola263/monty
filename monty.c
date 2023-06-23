#include "monty.h"
mem_t number = {0, 0, NULL, NULL, NULL};
/**
 * main - This the interpreter entry point
 * @ac: argument counter
 * @av: an array of pointers to strings
 *
 * Return: always zero on success
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	FILE *fd = NULL;
	char *line_read[BUFFER], *parse_buff[PARSE];
	size_t num = 0;
	stack_t *h = NULL;
	/*size_t count;*/

	if (ac != 2)
	{
		exit_msg(av[0], 90);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		exit_msg(av[1], 91);
	}

	number.headstack = &h; /* head of the stack around program */
	number.readline = line_read; /* pointer to buffer holding read lines */
	buff_fill(line_read, BUFFER);
	buff_fill(parse_buff, PARSE);
	/* function to read line from the file */
	_readline(line_read, &num, fd, av[1]);
	fclose(fd);
	/* function to tokenize read line into each word */
	parser(line_read, parse_buff, &h);
	_free_stack(&h);
	_free(line_read);
	buff_fill(line_read, BUFFER);

	return (0);
}
