#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - Execute a user-provided command.
 * @cmd: The command to execute.
 * @args: An array of arguments for the command.
 *
 * This function forks a new process to execute the given command with the
 * provided arguments. It handles both the child and parent processes,
 * waiting for the child to complete its execution.
 *
 * Return: (0) on success, (-1) on failure.
 */
int execute_command(char *cmd, char **args)
{
	pid_t child_pid;
	int status;

	if (cmd == NULL)
		return (-1);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_pid == 0)
	{
		if (execvp(cmd, args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}

