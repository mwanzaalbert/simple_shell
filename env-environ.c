#include "shell.h"

/* environ - array of pointers to environment variables */
extern char **environ;

/**
 * env_environ - Get the pointer to the environ array
 *
 * Return: Pointer to the environ array
 */
char **env_environ(void)
{
    return environ;
}
