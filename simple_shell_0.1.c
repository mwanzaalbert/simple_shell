#include "shell.h"

#define MAX_INPUT_LENGTH 1024

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_LENGTH];
    char *args[2];
    int status;
    
    while (1) {
        printf("$ ");
        
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            // Handle end of file (Ctrl-D)
            printf("\n");
            exit(0);
        }
        
        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline
        
        args[0] = input;
        args[1] = NULL;
        
        pid_t pid = fork();
        if (pid == -1) {
            // Handle fork error
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Child process
            execve(args[0], args, environ);
            perror("execve");
            exit(1);
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }
    
    return 0;
}
