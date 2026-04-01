/*
** EPITECH PROJECT, 2026
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

void shift_env(char **env, int i)
{
    while (env[i]) {
        env[i] = env[i + 1];
        i++;
    }
}

char **remove_one_var(char **env, char *name)
{
    int i = 0;
    int len;

    if (!env || !name)
        return (env);
    len = strlen(name);
    while (env[i]) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=') {
            free(env[i]);
            shift_env(env, i);
            i--;
        }
        i++;
    }
    return (env);
}

char **my_unsetenv(char **args, char **env)
{
    int i = 1;

    if (!args || !args[i])
        return (env);
    while (args[i]) {
        remove_one_var(env, args[i]);
        i++;
    }
    return (env);
}

int main(int ac, char **av, char **envp)
{
    char **my_env = copy_environment(envp);

    shell_loop(my_env);
    return 0;
}
