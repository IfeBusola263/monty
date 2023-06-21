#include "monty.h"
/**
 * main - This the interpreter entry point
 * @ac: argument counter
 * @av: an array of pointers to strings
 *
 * Return: always zero on success
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	FILE *fd;
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

	buff_fill(line_read, BUFFER);
	buff_fill(parse_buff, PARSE);
	_readline(line_read, &num, fd, av[1]);
	parser(line_read, parse_buff, &h);
	buff_fill(line_read, BUFFER);
       	return (0);
}
