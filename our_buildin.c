#include "shell.h"

/**
*our_atoi - function that creates an integer from a strin
*@str: strngd pointer
*Return: the result
*/
int our_atoi(char *str)
{
	int r, ngis = 1, lagf, result;
	unsigned int output = 0;

	for (r = 0; str[r] != '\0' && lagf != 2; r++)
	{
		if (str[r] == '-')
			ngis *= -1;

		if (str[r] >= '0' && str[r] <= '9')
	{
		lagf = 1;
		output *= 10;
		output += (str[r] - '0');
	}
		else if (lagf == 1)
			lagf = 2;
	}
	
	if (ngis == -1)
		result = -output;
	else
		result = output;
	return (result);
}

/**
 * our_exxit - Shell exxit
 * @exit: Args format
 * Return: status exit
 */
void our_exxit(char **exxit)
{
	int e, x;

	if (exxit[1])
	
	{
	x  = atoi(exxit[1]);
	if (x <= -1)
	x = 2;
	free(exxit);
	exit(x);
	}

	for (e = 0; exxit[e]; e++)
	free(exxit[e]);
	free(exxit);
	exit(0);

}

/**
 * our_environ - Displays current environment
 * @current: Args
 * Return: Success (Always 0)
 */
void our_environ(char **curr __attribute__ ((unused)))
{
	int e;

	for (e = 0; environ[e]; e++)
	{
		puts(environ[e]);
		puts("\n");
	}
}

/**
 * our_setenv - New environment Initialization
 * @rmv: Args format
 * Return: Success(Always 0)
 */

void our_setenv(char **set)
{
        int c;

	char *new_env_var = (char *)malloc(new_len + set_len + 2);

        if (!set[0] || !set[1] || !set[2])
        {
                perror(getenv("_"));
                return;
        }

	size_t new_len = strlen(set[1]);
	size_t set_len = strlen(set[2]);

        for (c = 0; environ[c]; c++)
        {
		if (strncmp(set[1], environ[c], new_len) == 0 && environ[c][new_len] == '=')
        
		char *new_env_var = (char *)malloc(new_len + set_len + 2);        
                if (!new_env_var)
                {
			perror("malloc");
			return;
		}
		strcpy(new_env_var, set[1]);
		strcat(new_env_var, "=");
		strcat(new_env_var, set[2]);		                }
		environ[a] = new_env_var;
		return;
	}
}
char *new_env_var = (char *)malloc(new_len + set_len + 2);
if (!new_env_var)
	{
	perror("malloc");
	free(new_env_var);
	return;
	}
	strcpy(new_env_var, set[1]);
	strcat(new_env_var, "=");
	strcat(new_env_var, set[2]);
	
	int env_count = 0;
	while (environ[env_count] != NULL)
	{
	env_count++;
	}
char **new_environ = (char **)malloc((env_count + 2) * sizeof(char *));
if (!new_environ)
{
perror("malloc");
free(new_env_var);
return;
}
for (int c = 0; c < env_count; c++)
{
	new_environ[c] = environ[c];
}

new_environ[env_count] = new_env_var;
new_environ[env_count + 1} = NULL;

environ = new_environ;
}

/**
 * our_unsetenv - Deletes an environment variable
 * @rem: arg format
 * Return: Success 0
 */
void our_unsetenv(char **rmv)
{
	int u, r;

	if (!rmv[1])
	{
		perror(getenv("_"));
		return (void);
	}
	for (u = 0; environ[u]; u++)
	{
		r = 0;
		if (rmv[1][r] == environ[u][r])
		{
		while (rmv[1][r])
		{
			if (rmv[1][r] != environ[u][r]
				break;

				r++;
		}
		if (rmv[1][r] == '\0')
		{
			free(environ[u]);
			environ[u] = environ[u + 1];
			
			while (environ[u])
		{
			environ[u] = environ[u + 1];
			u++;
		}
		return (void);
		}
	}
}
}
