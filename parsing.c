/*
** EPITECH PROJECT, 2026
** parsing.c
** File description:
** parsing.c
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

int count_tokens(char *line)
{
    int count = 0;
    int i = 0;

    while (line[i]) {
        while (line[i] && (line[i] == ' ' ||
                line[i] == '\t' || line[i] == '\n'))
            i++;
        if (line[i])
            count++;
        while (line[i] && (line[i] != ' ' &&
                line[i] != '\t' && line[i] != '\n'))
            i++;
    }
    return count;
}

char **split_line(char *line)
{
    char *token;
    int n_tokens = count_tokens(line);
    char **tokens = malloc(sizeof(char *) * (n_tokens + 1));
    int i = 0;

    if (!tokens)
        return NULL;
    token = strtok(line, " \t\n");
    while (token != NULL) {
        tokens[i] = token;
        i = i + 1;
        token = strtok(NULL, " \t\n");
    }
    tokens[i] = NULL;
    return tokens;
}
