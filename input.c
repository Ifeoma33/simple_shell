#include "shell.h"
#include <stdio.h>

void display_prompt(void) {
    char prompt[] = "#cisfun$ ";
    write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

char* read_input(void) {
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t input_size;

    input_size = getline(&buffer, &bufsize, stdin);

    if (input_size == -1) {
        write(STDOUT_FILENO, "\n", 1);
        free(buffer);
        _exit(0);
    }

    buffer[input_size - 1] = '\0';
    return buffer;
}

