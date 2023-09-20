#include "shell.h"

/**
*our_atoi - function that creates an integer from a strin
*@str: strngd pointer
*Return: the result
*/
int our_atoi(char *str)
{
	int r, ngis = 1, lagf, result;
	unsigned int output = 0;

	for (r = 0; str[r] != '\0' && lagf != 2; r++)
	{
		if (str[r] == '-')
			ngis *= -1;

		if (str[r] >= '0' && str[r] <= '9')
	{
		lagf = 1;
		output *= 10;
		output += (str[r] - '0');
	}
		else if (lagf == 1)
			lagf = 2;
	}
	
	if (ngis == -1)
		result = -output;
	else
		result = output;
	return (result);
}

/**
 * our_exxit - Shell exxit
 * @exit: Args format
 * Return: status exit
 */
void our_exxit(char **exxit)
{
	int e, x;

	if (exxit[1])
	
	{
	x  = atoi(exxit[1]);
	if (x <= -1)
	x = 2;
	free(exxit);
	exit(x);
	}

	for (e = 0; exxit[e]; e++)
	free(exxit[e]);
	free(exxit);
	exit(0);

}

/**
 * our_environ - Displays current environment
 * @current: Args
 * Return: Success (Always 0)
 */
void our_environ(char **curr __attribute__ ((unused)))
{
	int e;

	for (e = 0; environ[e]; e++)
	{
		puts(environ[e]);
		puts("\n");
	}
}

/**
 * our_setenv - New environment Initialization
 * @new: Args format
 * Return: Success(Always 0)
 */

void our_setenv(char *new, char *set)
{
	if (!new || !set)
{
	perror("our_setenv");
	return (void);
}
	char result = setenv(new, set, 1);
	
	if (result != 0)
	{
	perror("our_setenv");
	}
}

/**
 * our_unsetenv - Deletes an environment variable
 * @rem: arg format
 * Return: Success 0
 */
void our_unsetenv(char *set)
{
	if (!set)
	{
		perror("our_unsetenv");
		return (void);
	}

	char output = unsetenv(set);

	if (output != 0)
	{
		perror("our_unsetenv");
	}
}
