#include "shell.h"
/**
 * execute - Executes commands
 *@command: Executable
 */
void execute(char **command)
{
	int e, period;

	if (!command || !command[0])
		return;
	e = fork();
	if (d == -1)
	{
		perror(_getenv("_"));
	}
	if (e == 0)
	{
		execve(command[0], command, environment);
		perror(command[0]);
		exit(EXIT_FAILURE);
	}
		wait(&period);
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
	char *token = strtok(copy, delimiter);

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
token = strtok(NULL, delimiter);
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
