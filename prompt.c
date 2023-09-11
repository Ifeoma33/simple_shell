#include "main.h"
/**
  * main - entry point
  * @length: count the length of the string.
  * @prompt: prompt for user
  * @read: gets user input and reads it to stdin
  * @str: user input to be displayed
  */
int main()
{
	size_t length = 0;
	char *prompt;
	ssize_t read;
	char *str;


	prompt = "IK$ ";
	while (1)
	{
	/* prints the prompt */
		printf("%s", prompt);
	/* gets user input and reads it to stdin */
		read = getline(&str, &length, stdin);
	      /* check if EOf or an error occurred */
	if (read == -1)
	{
		perror("existing..\n");
		return (1);
	printf("%s\n", str);
	
	free (str);
	}
	}
	return (0);
}	
