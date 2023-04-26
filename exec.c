#include "shell.h"

void execute_command(char **args) {
    pid_t pid = fork();
    int status;
    
    if (pid == -1) {
        // Handle fork error
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            // Handle execvp error
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        do {
            if (waitpid(pid, &status, WUNTRACED) == -1) {
                // Handle waitpid error
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
