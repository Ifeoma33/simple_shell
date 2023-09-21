#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * prompt - Displays a command prompt.
 */
void prompt(void)
{
	printf("$ ");
}

/**
 * read_line - Reads a line of input from the user.
 *
 * Return: A pointer to the input line.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		return (NULL);
	}

	if (line[read - 1] == '\n')
	{
		line[read - 1] = '\0';
	}

	return (line);
}

/**
 * tokenize - Tokenizes a string into an array of tokens.
 * @input: The input string to tokenize.
 *
 * Return: An array of tokens.
 */
char **tokenize(char *input)
{
	char **tokens = malloc(sizeof(char *) * 64);
	char *token;
	int index = 0;

	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " ");
	while (token != NULL)
	{
		tokens[index] = token;
		index++;

		token = strtok(NULL, " ");
	}
	tokens[index] = NULL;

	return (tokens);
}

