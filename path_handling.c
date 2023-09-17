#include "shell.h"

/**
 *our_getenv - string copy of our environmenr
 *@valoue: Global variable
 *Return: Valoue string
 *
 */

char *our_getenv(const char *valoue)
{
	if (!valoue)
	return (NULL);

	int g = 0;

	while (environ[g] != NULL)
	{

	int e = 0;

	while (valoue[e] != '\0' && name[e] == environ[g][e])
	{
	e++;
	}
	if (valoue[e] == '\0')
		return (environ[g] + e + 1);
	g++;
	}
	return (NULL);
}
