#include "shell.h"

/**
 *checkbuild - status of buildin
 * @info: Args format
 * Return: Pointer
 */
void (*checkbuild(char **info))(char **info)
{
	int x = 0;
	int e = 0;

		ourbuild T[] = {
		{"unsetenv", our_unsetenv},
		{"exit", our_exxit},
		{"env", our_environ},
		{"setenv", our_setenv},
		{NULL, NULL}
	};

	for (x = 0; T[x].value; x++)
	{
		if (T[x].value[e] == info[0][e])
		{
		for (e = 0; info[0][e]; e++)
		{
			if (T[x].value[e] != info[0][e])
				break;
		}
		if (!info[0][e])
			return (T[x].cmd);
		}
	}
	return (0);
}
