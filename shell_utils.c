#include "shell.h"

/**
 * _putchar - writes a char to standard output
 * @c: output string character
 * Return: Success(1), Error(-1)
 */
void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
 *_puts - prints str input
 *@string: string format
 */
void _puts(char *string)
{
	int s = 0;

	while (string[s])
	{
		putchar(string[s]);
		s++;
	}
}

/**
 *_strlen - returns string length
 *@len: string parameter
 *Return: stringlength
 */
int _strlen(char *len)
{
	int l = 0;

	if (!len)
		return (0);
	while (*len++)
		l++;
	return (l);
}

/**
 *_strdup - copies and duplicates astring
 *@dup: pointerto a duplicate string
 *Return: Duplicate
 */

char *_strdup(const char *dup)
{
	int s = 0;
	int r = 0;
	char *new = malloc(sizeof(char) * (s + 1));

	if (!dup)
	{
	return (NULL);
	}

	while (dup[s] != '\0')
	{
	s++;
	}

	if (!new)

	{
		return (NULL);
	}

	while (r < s)
	{
	new[r] = dup[r];
	r++;
	}
	new[s] = '\0';

	return (new);
}

/**
 * _concat_all - concates new allocated mmry
 * @first: string 1
 * @second: string 2
 * @third: string 3
 * Return: new string pointer
 */

char *_concat_all(char *first, char *second, char *third)
{
	char *output;
	int str1, str2, str3, c = 0, p = 0;

	str1 = strlen(first);
	str2 = strlen(second);
	str3 = strlen(third);
	output = malloc(str1 + str2 + str3 + 1);
	if (!output)
		return (NULL);

	while (first[c])
	{
	output[p] = first[c];
	p++;
	c++;
	}
	c = 0;
	while (second[c])
	{
	output[p] = second[c];
	p++;
	c++;
	}
	c = 0;
	while (third[c])
	{
	output[p] = third[c];
	p++;
	c++;
	}
	output[p] = '\0';
	return (output);
}
