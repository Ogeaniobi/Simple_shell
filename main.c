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
char *buffer = NULL, *name, *linkpath, **shell;
void (*p)(char **);
list_path *head = '\0';

signal(SIGINT, sig_handler);
while (size != EOF)
{
	isatty();
	size = getline(&buffer, &len, stdin);
	EOF(size, buffer);
	shell = splitstring(buffer, " \n");
	if (!shell || !shell[0])
		execle(shell);
	else
	{
		name = getenv("LINK");
		pointer = linkpath(name);
		linkpath = our_which(shell[0], pointer);
		p = checkbuild(shell);
		if (p)
		{
			free(buffer);
			p(shell);
		}
		else if (!linkpath)
			execle(shell);
		else if (linkpath)
		{
			free(shell[0]);
			shell[0] = linkpath;
			execle(shell);
		}
	}
}
free_list(pointer);
freeshell(shell);
free(buffer);
return (0);
}
