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
 * @exxit: Args format
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
 * @curr: Args
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
 * @set: Args format
 * Return: Success(Always 0)
 */

void our_setenv(char **set)
{
	int a, b, c;

	if (!set[1] || !set[2])
	{
	perror(getenv("_"));
	return;
	}

	for (a = 0; environ[a]; a++)
	{
		b = 0;
		if (set[1][b] == environ[a][b])
		{
			while (set[1][b])
			{
				if (set[1][b] != environ[a][b])
					break;

				b++;
			}
			if (set[1][b] == '\0')
			{
				c = 0;
				while (set[2][c])
				{
					environ[a][b + 1 + c] = set[2][c];
					c++;
				}
				environ[a][b + 1 + c] = '\0';
				return;
			}
		}
	}
	if (!environ[a])
	{
		environ[a] = our_conkatall(set[1], "=", set[2]);
		environ[a + 1] = '\0';
	}
}

/**
 * our_unsetenv - Deletes an environment variable
 * @rmv: arg format
 * Return: Success 0
 */

void our_unsetenv(char **rmv)
{
	int u, r;

	if (!rmv[1])
	{
		perror(getenv("_"));
		return;
	}
	for (u = 0; environ[u]; u++)
	{
		r = 0;
		if (rmv[1][r] == environ[u][r])
		{
		while (rmv[1][r])
		{
			if (rmv[1][r] != environ[u][r])
			r++;
		}
		if (rmv[1][r] == '\0')
		{
			free(environ[u]);
			environ[u] = environ[u + 1];

		while (environ[u])
		{
			environ[u] = environ[u + 1];
			u++;
		}
		return;
		}
	}
}
}

