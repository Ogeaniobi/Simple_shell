#include "shell.h"
/**
 * interact - Shell Interactive Mode
 * @arv: Structure Parameter
 * Return: Succes (1), else (0)
 */
int interact(list_t *arv)
{
	return (isatty(STDIN_FILENO) && (*arv->readfd <= 2));
}

/**
 * our_delimiter - Delimiter checker
 * @delimiter: String to be checked
 * @n: Parameter
 * Return: Success 1, Error 0
 */
int our_delimiter(char n, char *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == n)
			return (1);
	return (0);
}
/**
 * _isalpha - Alphabets checker
 * @arv: Input parameter
 * Return: True (1), (0)
 */
int _isalpha(int arv)
{
	if ((arv >= 'a' && arv <= 'z') || (arv >= 'A' && arv <= 'Z'))
		return (1);
	else
		return (0);
}
