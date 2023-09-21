#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_user_input - Handles user input and executes commands.
 * @command: The user input command.
 *
 * This function takes user input, identifies the command, and executes it
 * based on the provided command. It supports "exit," "ls," "list_path," and
 * "env" commands.
 */
void handle_user_input(char *command)
{
	char *exit_command = "exit";
	char *list_files_command = "ls";
	char *list_path_command = "list_path";
	char *env_command = "env";

	if (strcmp(command, exit_command) == 0)
	{
		exit_shell();
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
}

/**
 * main - Entry point for the simple shell program.
 *
 * This function serves as the main entry point for the simple shell. It
 * displays a command prompt, reads user input, and executes commands
 * the user. The shell supports the "exit" command to exit the shell,
 * "ls" to list files in the current directory, "list_path" to display the
 * current working directory, and "env" to print the environment.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command;

	while (1)
	{
		prompt();             /* Display the prompt */
		command = read_line(); /* Read user input */

		if (command == NULL) /* Handle Ctrl+D (EOF) */
		{
			break;
		}

		handle_user_input(command);

		free(command);
	}

	return (0);
}

