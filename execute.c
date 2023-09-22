#include "shell.h"
#include <stdio.h>

void execute_command(char *input) {
    pid_t pid;
    char *token = strtok(input, " ");
    char *args[10];
    int i = 0;

    pid = fork();

    if (pid == -1) {
        perror("fork");
    } else if (pid == 0) {
        execve(args[0], args, NULL);
        perror("execve");
        _exit(1);
    } else {
        wait(NULL);
    }

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;
}

