#include "shell.h"

int main(void) {
    char *buffer = NULL;

    while (1) {
        display_prompt();
        buffer = read_input();

        if (strcmp(buffer, "exit") == 0) {
            free(buffer);
            _exit(0);
        }

        execute_command(buffer);
        free(buffer);
    }

    return 0;
}

