#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(int argc, char *argv[], char *envp[]) {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH];
    
    while (1) {
        print_prompt();
        read_input(input);
        parse_input(input, args);
        execute_command(args);
    }
    
    return 0;
}
