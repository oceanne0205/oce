/*
** EPITECH PROJECT, 2026
** shell.c
** File description:
** shell.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

int count_env_vars(char **envp)
{
    int i = 0;

    while (envp && envp[i])
        i++;
    return i;
}

char **copy_environment(char **envp)
{
    int size = count_env_vars(envp);
    char **new_env = malloc(sizeof(char *) * (size + 1));

    if (!new_env)
        return NULL;
    for (int i = 0; i < size; i++)
        new_env[i] = my_strdup(envp[i]);
    new_env[size] = NULL;
    return new_env;
}

void display_env(char **my_env)
{
    if (!my_env)
        return;
    for (int i = 0; my_env[i]; i++)
        my_printf("%s\n", my_env[i]);
}

void free_env(char **env)
{
    if (!env)
        return;
    for (int i = 0; env[i] != NULL; i++) {
        free(env[i]);
    }
    free(env);
}
