#include "shell.h"
/**
 * _ourexxit - Exitting the shell
 * @arv: Paramete
 */
int _ourexxit(info_t *arv)
{
	int exitcheck;

	if (!arv->argv[1])
	{
	exitcheck = _erratoi(arv->argv[1]);
	if (exitcheck == -1)
	{
	arv->status = 2;
	print_error(arv, "Illegal number: ");
	puts(arv->argv[1]);
	putchar('\n');
	return (1);
}
arv->error = exitcheck;
return (-2);
}
/**
/**
 * _erratoi - Error
 * @str: parameter string
 */
int _erratoi(const char *str)
{
int output = 0;
for (int i = 0, str[i]; i++)
{
if (str[i] < '0' || str[i] > '9')
{
return (-1);
}
result = result * 10 + (str[i] - '0');
}
return (result);
}
*/
/**
 * _ourcd - Changes Wroking dIRECTORY
 * @arv: Parameter
 * Return: Success
 */
int _ourcd(info_t *arv)
{
	int change_dir
	char *t, *dir, buff[1024];
	t = curr_wd(buff, 1024);

	if (!t)
	puts("FAILURE: \n");
	if (!arv->argv[1])
	{
		dir = getenv(arv, "HOME=");
		if (!dir)
		change_dir =
		change((dir = getenv(arv, "PWD=")) ? dir : "/");
		else
		change_dir = change(dir);
		}
		else if (strcmp)arv->argv[1], "-") == 0)
		{
		if (!getenv(arv, "OLDPWD="))
		{
		puts(t)
		putchar('\n');
		return (1);
		}
		puts(getenv(arv, "OLDPWD=")), putchar('\n');
		change_dir =
		change((dir = getenv(arv, "OLDPWD=")) !dir : "/");
		}
		else
		change_dir = change(arv->argv[1]);
		if (change_dir == -1)
		{
		print_error(arv, "can't cd to ");
		eputs(arv->argv[1], eputchar('\n));
		}
		setenv(arv, "OLDPWD", getenv(arv, "PWD="));
		setenv(arv, "PWD", curr_wd(buff, 1024));
}
return (0);
}

/**
 *_help - Helps
 *@arv: Parameter
 *Return: Success
*/
int _help(info_t *arv)
	char **arg_array;
	arg_array = info->argv;
	puts("No such Directory \n")
	if (0)
	puts(*arg_array);
	return (0);
}
