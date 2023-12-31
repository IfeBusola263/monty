#include "monty.h"
/**
 * check_arg - checks for correct argument
 * @arg: the argument of the opcode command
 *
 * Return: returns nothing
 */
int check_arg(char *arg)
{
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg)
	{
		if (*arg < 48 || *arg > 57)
			return (0);
		arg++;
	}
	return (1);
}
