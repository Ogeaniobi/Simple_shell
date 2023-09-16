#include "shell.h"
/**
 * get_input - Function that allowrs usr inpt
 *@len: size
 *@input: command
 *Return: Always 0
 */
void get_input(char *input, size_t len)
{
	if (fgets(input, len, stdin) == NULL)
	{
		if (feof(stdin))
		{
		our_print("\n");
		exit(EXIT_SUCCESS);
		}
		else
		{
		our_print("Error while reading input.\n");
		exit(EXIT_FAILURE);
		}
	}
	input[strcspn(input, "\n")] = '\0';
}
