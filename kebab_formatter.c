  /*
** EPITECH PROJECT, 2026
** kebab.c
** File description:
** kebab.c
*/


#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
      write(1, &c, 1);
}

int get_type(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    if (c >= '0' && c <= '9')
        return (2);
    return (0);
}

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

void print_word(char *str, int *i)
{
    int type = get_type(str[*i]);

    while (str[*i] != '\0' && get_type(str[*i]) == type) {
        my_putchar(to_lower(str[*i]));
        (*i)++;
    }
}

void process_kebab(char *str)
{
    int i = 0;
    int first = 1;

    while (str[i] != '\0') {
        if (get_type(str[i]) == 0) {
            i++;
            continue;
        }
        if (first == 0)
            my_putchar('-');
        print_word(str, &i);
        first = 0;
    }
    my_putchar('\n');
}
