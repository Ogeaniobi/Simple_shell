#include "shell.h"
/**
 * sig_handler - If Control copy is prompted
 * @sign_m: parameter
 */
void sig_handler(int sign_m)
{
	if (sign_m == SIGINT)
	{
		put("\n#cisfun$ ");
	}
}

/**
 * our_EOF - End of File
 * @value: Getline Function
 * @indexx: buffer
 */
void our_EOF(int value, char *indexx)
{
	(void)indexx;
	if (value == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			puts("\n");
			free(index);
		}
		exit(0);
	}
}
/**
 * our_isatty - Function for isatty
 * Return: Success Value
 */
void our_isatty(void)
{
	if (isatty(STDIN_FILENO))
		puts("#cisfun$ ");
}

/**
 * main - Entry point
 * Return: Success(Always 0)
 *
 */
int main(void)
{
char input[110];
ssize_t len = 0;
char *buff = NULL, *value, *pathname, **arv;
size_t size = 0;
list_path *head = '\0';
void (*f)(char **);

signal(SIGINT, sig_handler);
while (len != EOF)
{
	/*_isatty();*/
	len = getline(&buff, &size, stdin);
	_EOF(len, buff);
	arv = splitstring(buff, " \n");
	if (!arv || !arv[0])
		execute(arv);
	else
	{
		value = our_getenv("PATH");
		head = linkpath(value);
		pathname = our_which(f_name[0], pointer);
		if = checkbuild(info);
		if (f)
		{
			free(index);
			f(info);
		}
		else if (!pathname)
			execute(arv);
		else if (pathname)
		{
			free(arv[0]);
			arv[0] = pathname;
			execute(arv);
		}
	}
}
free_list(list);
freelist(list);
free(index);
return (0);
}

char input[110];

	while (true)
	{
	show_promptme();
	get_input(input, sizeof(input));
	exec_mycommand(input);
	}
return (0);
}
