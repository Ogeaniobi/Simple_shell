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
