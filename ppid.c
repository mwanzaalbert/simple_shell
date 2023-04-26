#include "shell.h"

void print_ppid() {
    printf("PPID=%d\n", getppid());
}
