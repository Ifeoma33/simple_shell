#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

/**
 * list_files_in_path - Lists files in the current directory.
 */
void list_files_in_path(void)
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir(".");
	if (dir == NULL)
	{
		perror("opendir");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_REG)
		{
			printf("%s\n", entry->d_name);
		}
	}

	closedir(dir);
}

/**
 * list_path - Lists the current working directory.
 */
void list_path(void)
{
	char path[1024];

	if (getcwd(path, sizeof(path)) != (char *)NULL)
	{
		printf("Current directory: %s\n", path);
	}
	else
	{
		perror("getcwd");
	}
}

/**
 * exit_shell - Exits the shell gracefully.
 */
void exit_shell(void)
{
	printf("Exiting the shell.\n");
	exit(0);
}

/**
 * print_environment - Prints the current environment.
 */
void print_environment(void)
{
	extern char **environ;
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

