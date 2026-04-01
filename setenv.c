/*
** EPITECH PROJECT, 2026
** my_setenv.c
** File description:
** my_setenv.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

char *make_line(char *name, char *value)
{
    int len = strlen(name) + strlen(value) + 2;
    char *new = malloc(len);

    if (!new)
        return (NULL);
    my_strcpy(new, name);
    my_strcat(new, "=");
    my_strcat(new, value);
    return (new);
}

int replace_env_var(char **env, char *name, char *value)
{
    int len = strlen(name);

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=') {
            free(env[i]);
            env[i] = make_line(name, value);
            return (1);
        }
    }
    return (0);
}

char **add_env_var(char **env, char *name, char *value)
{
    int i = count_env_vars(env);
    char **new_env = malloc(sizeof(char *) * (i + 2));
    int j = 0;

    if (!new_env)
        return (env);
    while (j < i) {
        new_env[j] = env[j];
        j++;
    }
    new_env[i] = make_line(name, value);
    new_env[i + 1] = NULL;
    free(env);
    return (new_env);
}

char **my_setenv(char **env, char *name, char *value)
{
    if (!name) {
        for (int i = 0; env[i]; i++) {
            my_printf(env[i]);
            my_putchar('\n');
        }
        return (env);
    }
    if (!value)
        value = "";
    if (replace_env_var(env, name, value))
        return (env);
    return add_env_var(env, name, value);
}
