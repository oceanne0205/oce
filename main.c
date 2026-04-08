/*
** EPITECH PROJECT, 2026
** main.c
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (ac == 2 && av[1][0] == '\0')
        my_putchar('\n');
    else {
        process_kebab(av[1]);
    }
    return 0;
}
