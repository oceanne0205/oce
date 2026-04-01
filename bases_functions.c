/*
** EPITECH PROJECT, 2026
** bases_functions.C
** File description:
** bases_functions.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

char *my_strdup(const char *src)
{
    int len = 0;
    char *dest;

    while (src[len])
        len++;
    dest = malloc(len + 1);
    if (!dest)
        return NULL;
    for (int i = 0; i < len; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return dest;
}

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n <= 0)
        return 0;
    while (i < n - 1 && s1[i] && s1[i] == s2[i]) {
        i++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
