#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT_LENGTH 1024
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void print_prompt();
void read_input(char *input);
void parse_input(char *input, char **args);
void execute_command(char **args);

#endif
