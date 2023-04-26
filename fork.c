#include "shell.h"

void fork_process() {
    pid_t pid = fork();
    
    if (pid == -1) {
        // Handle fork error
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("I am the child process (PID=%d)\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("I am the parent process (PID=%d)\n", getpid());
        printf("My child process has PID=%d\n", pid);
    }
}
