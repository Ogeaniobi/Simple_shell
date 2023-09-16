#include "shell.h"
/**
 * main - Entry point
 * Return: Success(Always 0)
 *
 */
int main(void)
{
	char input[110];

	while (true)
	{
	show_promptme();
	get_input(input, sizeof(input));
	exec_mycommand(input);
	}
return (0);
}
