#ifndef SHELL_H
#define SHELL_H

/* Function Declarations */
void prompt(void);
char *read_line(void);
char **tokenize(char *input);
int execute_command(char *cmd, char **args);
void list_files_in_path(void);
void list_path(void);
void exit_shell(void);
void print_environment(void);

#endif /* SHELL_H */

