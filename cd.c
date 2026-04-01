/*
** EPITECH PROJECT, 2026
** cd.c
** File description:
** cd.c
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

char *find_home(char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "HOME=", 5) == 0)
            return (env[i] + 5);
    }
    return (NULL);
}

char *get_cd_path(char **args, char **env)
{
    char *path = args[1];

    if (path == NULL || my_strcmp(path, "~") == 0)
        return (find_home(env));
    return (path);
}

void my_cd(char **args, char **env)
{
    char *path = get_cd_path(args, env);

    if (path == NULL)
        return;
    if (chdir(path) != 0) {
        my_printf("%s: No such file or directory.\n", path);
    }
}
