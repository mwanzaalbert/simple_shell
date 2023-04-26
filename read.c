#include "shell.h"

void read_input(char *input) {
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline
}
