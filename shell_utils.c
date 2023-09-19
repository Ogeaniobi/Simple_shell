#include "shell.h"

/**
 * our_putchar - writes a char to standard output
 * @c: output string character
 * Return: Success(1), Error(-1)
 */
void our_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
 *our_puts - prints str input
 *@string: string format
 */
int our_puts(char *string)
{
	int s = 0;

	if (!string)
		return (0);
	while (string[s] != '\0')
	{
		putchar(string[s]);
		s++;
	}
}

/**
 *our_strlen - returns string length
 *@len: string parameter
 *Return: stringlength
 */
int our_strlen(char *len)
{
	int l = 0;

	if (!len)
		return (0);
	while (*len++)
		l++;
	return (l);
}

/**
 *our_strdup - copies and duplicates astring
 *@dup: pointerto a duplicate string
 *Return: Duplicate
 */

char *our_strdup(const char *dup)
{
	if (!dup)
	{
	return (NULL);
	}

	int s = 0;

	while (dup[s] != '\0')
	{
	s++;
	}

	char *new = malloc(sizeof(char) * (s + 1));

	if (!new)

	{
		return (NULL);
	}
	int r = 0;

	while (r < s)
	{
	new[r] = dup[r];
	r++;
	}
	new[s] = '\0';

	return (new);
}

/**
 * our_conkatall - concates new allocated mmry
 * @first: string 1
 * @second: string 2
 * @third: string 3
 * Return: new string pointer
 */

char *our_conkatall(char *first, char *second, char *third)
{
	char *output
		int str1, str2, str3, c, p;

	str1 = strlen(first);
	str2 = strlen(second);
	str3 = strlen(third);
	output = malloc(str1 + str2 + str3 + 1);
	if (!output)
		return (NULL);
	C = 0;
	P = 0;
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
