#include "shell.h"

/**
*our_atoi - function that creates an integer from a strin
*@str: strngd pointer
*Return: the result
*/
int our_atoi(char *str)
{
	int r, ngis = 1, result;

	r = 0;
	result = 0;
	while (!((s[r] >= '0') && (s[i] <= '9')) && (s[r] != '\0'))
	{
		if (s[r] == '-')
		{
			ngis = ngis * (-1);
		}
		r++;
	}
	while ((s[r] >= '0') && (s[r] <= '9'))
	{
		result = (result * 10) + (sign * (s[r] - '0'));
		i++;
	}
	return (result);
}

/**
 * our_exxit - Shell exxit
 * @exit: Args format
 * Return: status exit
 */
int our_exxit(info_t *exit)
{
	int statusexxit;

	if (exit->argv[1]
	{
	statusexxit = _erratoi(exit->argv[1]);
	if (statusexxit == -1)
	{
		exit->status = 2;
		print_error(exit, "Undefined Integer: ");
		eputs(exit->argv[1]);
		eputchar('\n');
		return (1);
	}
	exit->err_num = _erratoi(exit->argv[1]);
	return (-2);
	}
	exit->err_num = -1;
	return (-2);
}

/**
 * our_environ - Displays current environment
 * @current: Args
 * Return: Success (Always 0)
 */
void our_environ(char **curr)
{
	print_list_str(curr->env);
	return (0);
}

/**
 * our_setenv - New environment Initialization
 * @new: Args format
 * Return: Success(Always 0)
 */

void our_setenv(char **new)
{
	if (new->argc != 3)
	{
		eputs("Unspeciafied urguement\n");
		return (1);
	}
	if (setenv(new, new->argv[1], new->argv[2]))
		return (1);
	return (0);
}

/**
 * our_unsetenv - Deletes an environment variable
 * @rem: arg format
 * Return: Success 0
 */
void our_unsetenv(char **rem)
{
	int r;

	if (rem->argc == 1)
	{
		eputs("Very less args:\n");
		return (1);
	}
	for (r = 1; r <= rem->argc; r++)
		our_unsetenv(rem, rem->argv[i]);
		return (0);
}
