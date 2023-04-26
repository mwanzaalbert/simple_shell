#include "shell.h"

void parse_input(char *input, char **args) {
    int i = 0;
    char *arg = strtok(input, " ");
    
    while (arg != NULL && i < MAX_INPUT_LENGTH - 1) {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    
