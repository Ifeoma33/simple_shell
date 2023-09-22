#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/* Function prototypes */
void display_prompt(void);
char* read_input(void);
void execute_command(char *input);

#endif /* SHELL_H */

