#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point for the simple shell program.
 *
 * This function serves as the main entry point for the simple shell. It
 * displays a command prompt, reads user input, and executes commands entered by
 * the user. The shell supports the "exit" command to exit the shell,
 * "list_files" to list files in the current directory, "list_path" to
 * display the current working directory, and "env" to print the environment.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *command;
    char *exit_command = "exit";
    char *list_files_command = "ls";
    char *list_path_command = "list_path";
    char *env_command = "env";

    while (1)
    {
        prompt();             /* Display the prompt */
        command = read_line(); /* Read user input */

        if (command == NULL) /* Handle Ctrl+D (EOF) */
        {
            break;
        }

        if (strcmp(command, exit_command) == 0)
        {
            exit_shell();
            break;
        }
        else if (strcmp(command, list_files_command) == 0)
        {
            list_files_in_path();
        }
        else if (strcmp(command, list_path_command) == 0)
        {
            list_path();
        }
        else if (strcmp(command, env_command) == 0)
        {
            print_environment();
        }
        else
        {
            char **args = tokenize(command);
            if (args != NULL)
            {
                execute_command(args[0], args);
                free(args);
            }
        }

        free(command);
    }

    return 0;
}

