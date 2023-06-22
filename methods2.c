#include "monty.h"
/**
 * check_args - checks for correct argument
 * @arg: the argument of the opcode command
 *
 * Return: returns nothing
 */
int check_arg(char *arg)
{
	while (*arg)
	{
		if (*arg < 48 || *arg > 57)
			return (0);
		arg++;
	}
	return (1);
}
