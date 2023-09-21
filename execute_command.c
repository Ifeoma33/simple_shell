#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - Executes a user-provided command.
 * @cmd: The command to execute.
 * @args: An array of arguments for the command.
 *
 * Return: (0) on success, (-1) on failure.
 */
int execute_command(char *cmd, char **args)
{
    pid_t child_pid;
    int status;

    if (cmd == NULL)
        return -1;

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        return -1;
    }

    if (child_pid == 0)
    {
        if (cmd[0] != '/')
        {
            /* Prepend /bin/ to the command if it's not an absolute path */
            char cmd_with_path[256];
            snprintf(cmd_with_path, sizeof(cmd_with_path), "/bin/%s", cmd);
            if (execvp(cmd_with_path, args) == -1)
            {
                perror("execvp");
                _exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* Execute the command */
            if (execvp(cmd, args) == -1)
            {
                perror("execvp");
                _exit(EXIT_FAILURE);
            }
        }
    }
    else
    {
        /* Wait for the child process to finish */
        wait(&status);
    }

    return 0;
}

