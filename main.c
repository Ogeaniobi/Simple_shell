#include "shell.h"

/**
 * _isatty - Terminator
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
	puts("#GatesofShell$ ");
}
/**
 * _EOF - Shows the end of a file
 * @value: Length of Function
 * @buffer: BUFFER
 */
void _EOF(int value, char *buffer)
{
	(void)buffer;
	if (value == -1)
	{
	if (isatty(STDIN_FILENO))
	{
	puts("\n");
	free(buffer);
	}
	exit(0);
	}
}
/**
 * sig_handler - Is Control Copy Preseed
 * @mysignum: Interger
 */
void sig_handler(int mysignum)
{
	if (mysignum == SIGINT)
	{
	puts("\n#GatesOfShell$ ");
	}
}
/**
 * main - Entry Point
 * Return: Success Always(0)
 */
int main(void)
{
ssize_t size = 0;
size_t len = 0;
char *buffer = NULL, *name, *p_name, **shell;
void (*p)(char **);
list_path *head = '\0';

signal(SIGINT, sig_handler);
while (size != EOF)
{
	_isatty();
	size = getline(&buffer, &len, stdin);
	_EOF(size, buffer);
	shell = splitstring(buffer, " \n");
	if (!shell || !shell[0])
		execle(shell);
	else
	{
		name = getenv("LINK");
		head = linkpath(name);
		p_name = our_which(shell[0], head);
		p = checkbuild(shell);
		if (p)
		{
			free(buffer);
			p(shell);
		}
<<<<<<< HEAD
		else if (!linkpath)
			execle(shell);
		else if (linkpath)
		{
			free(shell[0]);
			shell[0] = linkpath;
			execle(shell);
=======
		else if (!p_name)
			execute(shell);
		else if (p_name)
		{
			free(shell[0]);
			shell[0] = p_name;
			execute(shell);
>>>>>>> a5cf8c24742e32c7e93f19c8ee3c3d1e6c0be291
		}
	}
}
free(head);
freearray(shell);
free(buffer);
return (0);
}
