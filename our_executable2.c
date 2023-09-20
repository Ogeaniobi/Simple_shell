#include "shell.h"
/**
 * exec_mycommand - Executes commands
 *@execute: Command
 */
void exec_mycommand(const char *execute)
{
	pid_t baby_pid = fork();

	if (baby_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (baby_pid == 0)
	{
		execlp(execute, execute, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
}

/**
 * splitstring - String spillter
 * @split: splitted strng
 * @delimiter: xter to be split
 * Return: Pointers
 */
char **splitstring(char *split, const char *delimiter)
{
	int s = 0;
	int ss = 2;
	char **array = malloc(sizeof(char *) * ss);
	char *copy = malloc(strlen(split) + 1);
	char *token = strtok(copy, delim);

	if (array == NULL)
	{
		perror("our_getenv");
		return (NULL);
	}
	if (copy == NULL)
	{
		perror("our_getenv");
		free(array);
		return (NULL);
	}
	strcpy(copy, split);

while (token)
{
if (s >= ss - 1)
{
	ss *= 2;
	array = realloc(array, sizeof(char *) * ss);
	if (array == NULL)
	{
		perror("our_getenv");
		free(copy);
		return (NULL);
	}
}
array[s] = strdup(token);
token = strtok(NULL, delim);
s++;
}
array[s] = NULL;
free(copy);
return (array);
}

/**
 * freearray - Freeing function
 * @array: Pointers
 */
void freearray(char **array)
{
	int a;

	for (a = 0; array[a]; a++)
		free(array[a]);
	free(array);
}

/**
 * our_realloc - Re-allocation of mmory
 * @prv: last ponter before current
 * @prev_size: Size before
 * @curr_size: Current size
 * Return: New Size
 */
void *our_realloc(void *prv, unsigned int prev_size, unsigned int curr_size)
{
	char *prev;
	char *curr;
	unsigned int r;

	if (prv == NULL)
	return (malloc(curr_size));

	if (curr_size == prev_size)
	return (prv);

	if (curr_size == 0 && prv != NULL)
	{
		free(prv);
		return (NULL);
	}

	curr = malloc(curr_size);
	prev = prv;
	if (curr == NULL)
	return (NULL);

	if (curr_size > prev_size)
	{
	for (r = 0; r < prev_size; r++)
	curr[r] = prev[r];
	free(prv);
	for (r = prev_size; r < curr_size; r++)
	curr[r] = '\0';
	}

	if (curr_size < prev_size)
	{
	for (r = 0; r < curr_size; r++)
	curr[r] = prev[r];
	free(prv);
	}
	return (curr);
	}
