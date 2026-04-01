/*
** EPITECH PROJECT, 2026
** execute.c
** File description:
** execute.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

char *get_path_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            return env[i] + 5;
    }
    return NULL;
}

char *build_full_path(char *dir, char *cmd)
{
    char *full = malloc(strlen(dir) + strlen(cmd) + 2);

    if (!full)
        return NULL;
    my_strcpy(full, dir);
    my_strcat(full, "/");
    my_strcat(full, cmd);
    return full;
}

char *find_path(char *cmd, char **env)
{
    char *path = get_path_env(env);
    char *tmp;
    char *dir;
    char *full;

    if (!path)
        return NULL;
    tmp = my_strdup(path);
    dir = strtok(tmp, ":");
    while (dir) {
        full = build_full_path(dir, cmd);
        if (full && access(full, X_OK) == 0) {
            free(tmp);
            return full;
        }
        free(full);
        dir = strtok(NULL, ":");
    }
    free(tmp);
    return NULL;
}
