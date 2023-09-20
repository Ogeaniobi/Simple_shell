#include "shell.h"

/**
 * splitstring - String spillter
 * @split: splitted strng
 * @delimiter: xter to be split
 * Return: Pointers
 */

char **splitstring(char *split, const char *delim);

/**
 * checkbuild - status of buildin
 * @info: Args format
 * Return: Pointer
 */
void(*checkbuild(char **info)
{
	int x, e;
	ourbuild T[] = {
		{"exit", our_exxit},
		{"env", our_environ},
		{"setenv", our_setenv},
		{"unsetenv", our_unsetenv},
		{NULL, NULL}
	};

	x = 0;
	while (T[x].value)
	{
		e = 0;
		if (T[x].value[e] == info[0][e])
		{
	while (T[x].value[e] && T[x].value[e] == info[0][e])
		{
		e++;
		}
		if (!info[0][e])
			return (T[x].cmd);
		}
		x++;
	}
	return (0);
}
