/*
** EPITECH PROJECT, 2026
** read.c
** File description:
** read.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

void display_prompt(void)
{
    if (isatty(0))
        my_printf("$> ");
}

static char **handle_setenv(char **args, char **env)
{
    int arg_count = 0;

    while (args[arg_count])
        arg_count++;
    if (arg_count == 1) {
        display_env(env);
    } else if (arg_count > 3) {
        my_printf("setenv: Too many arguments.\n");
    } else {
        env = my_setenv(env, args[1], args[2]);
    }
    return (env);
}

static char **handle_unsetenv(char **args, char **env)
{
    if (!args[1]) {
        my_printf("unsetenv: Too few arguments.\n");
        return (env);
    }
    return (my_unsetenv(args, env));
}

char **check_builtins(char **args, char **env, int *found)
{
    *found = 1;
    if (my_strcmp(args[0], "env") == 0) {
        display_env(env);
        return (env);
    }
    if (my_strcmp(args[0], "cd") == 0) {
        my_cd(args, env);
        return (env);
    }
    if (my_strcmp(args[0], "setenv") == 0)
        return (handle_setenv(args, env));
    if (my_strcmp(args[0], "unsetenv") == 0)
        return (handle_unsetenv(args, env));
    *found = 0;
    return (env);
}

char **handle_command(char **args, char **my_env, int *should_exit)
{
    int is_builtin = 0;

    if (!args || !args[0])
        return (my_env);
    if (my_strcmp(args[0], "exit") == 0) {
        *should_exit = 1;
        return (my_env);
    }
    my_env = check_builtins(args, my_env, &is_builtin);
    if (is_builtin == 0)
        execute_command(args, my_env);
    return (my_env);
}

void shell_loop(char **my_env)
{
    char *line = NULL;
    char **args = NULL;
    size_t len = 0;
    int should_exit = 0;

    while (should_exit == 0) {
        display_prompt();
        if (getline(&line, &len, stdin) == -1)
            break;
        args = split_line(line);
        my_env = handle_command(args, my_env, &should_exit);
        free(args);
    }
    free(line);
    free_env(my_env);
}
