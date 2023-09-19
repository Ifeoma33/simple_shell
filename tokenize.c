#include "main.h"
/**
  * strtok - splits strings into command and argument
  * @str: Strings to be splited
  * @delim: delimenter to show where the string will be splitted
  * Return: 0
  */
char *_strtok (char *str, char *delim)
{
	delim = " \n";
	char *string_split = NULL;
	char *begin;	

	if ( string_split == NULL)
	{
		string_split = str;
	}
	if (string_split == NULL || *string_split == '\0')
	{
		return (NULL);
	}

	while (*string_split != '\0' && strchr(delim, *string_split) != NULL)
	{
		string_split++;
		if (*string_split == '\0')
		{
			return (NULL);
		}
		begin = string_split;
		while (*string_split != '\0' && strchr(delim, *string_split) == NULL)
		{
			string_split++;
		}
		if (*string_split != '\0')
		{
			*string_split = '\0';
		}
		return (begin);
	}
	return (0);
}


	
