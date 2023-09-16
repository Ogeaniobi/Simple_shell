#include "shell.h"

/**
 * our_print - creates a function that prints the string
 * @my_shell: Print Variablr
 * Return: Always (0)
 */

void our_print(const char *my_shell)
{
	write(STDOUT_FILENO, my_shell, strlen(my_shell));
}
