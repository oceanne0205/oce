/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putnbr(int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
    } else if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    } else {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    return (0);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

int mini_printf_form(char car, va_list args)
{
    if (car == '%')
        my_putchar('%');
    if (car == 'd' || car == 'i')
        my_putnbr(va_arg(args, int));
    if (car == 's')
        my_putstr(va_arg(args, char *));
    else if (car == 'c')
        my_putchar((char)va_arg(args, int));
    else {
        return (-1);
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            mini_printf_form(*format, args);
        } else
            my_putchar(*format);
        format++;
    }
    va_end(args);
    return 0;
}
