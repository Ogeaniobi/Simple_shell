#include "shell.h"

/**
 * Pointer to check built-in status
 */
typedef void(*BuiltInCommand)(char **info);

/**
 * checkbuild - status of buildin
 * @info: Args format
 * Return: Pointer
 */
BuiltInCommand checkbuild(char **info)
{
	int x, e;
	our_build T[] = {
		{"exit", our_exxit},
		{"env", our_environ},
		{"setenv", our_setenv},
		{"unsetenv", our_unsetenv}'
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
