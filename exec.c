/*
** EPITECH PROJECT, 2026
** exec.c
** File description:
** exec.c
*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"


int has_slash(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == '/')
            return (1);
        i++;
    }
    return (0);
}

void run_child(char *path, char **args, char **my_env)
{
    if (execve(path, args, my_env) == -1) {
        perror("execve");
        free(path);
        exit(EXIT_FAILURE);
    }
}

static void handle_wait(pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV)
            write(2, "Segmentation fault", 18);
        if (WTERMSIG(status) == SIGFPE)
            write(2, "Floating exception", 18);
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        if (WIFSIGNALED(status))
            write(2, "\n", 1);
    }
}

static void print_error(char *cmd)
{
    write(2, cmd, strlen(cmd));
    write(2, ": Command not found.\n", 21);
}

void execute_command(char **args, char **my_env)
{
    char *path;
    pid_t pid;

    if (!args || !args[0])
        return;
    path = (has_slash(args[0])) ?
        my_strdup(args[0]) : find_path(args[0], my_env);
    if (!path) {
        print_error(args[0]);
        return;
    }
    pid = fork();
    if (pid == 0)
        run_child(path, args, my_env);
    else if (pid > 0)
        handle_wait(pid);
    else
        perror("fork");
    free(path);
}
