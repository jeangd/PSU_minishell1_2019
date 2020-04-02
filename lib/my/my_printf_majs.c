/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printfS.c
*/

#include "my.h"

void my_putstr_unprintable(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        if (str[i] < 10 && (str[i] < 32 || str[i] >= 127))
            my_putstr("\\00");
        if (str[i] < 100 && str[i] > 10 && (str[i] < 32 || str[i] >= 127))
            my_putstr("\\0");
        if (str[i] > 100 && (str[i] < 32 || str[i] >= 127))
            my_putstr("\\");
        if (str[i] < 32 || str[i] >= 127) {
            my_put_octal(str[i]);
            i++;
        }
        my_putchar(str[i]);
        i++;
    }
}

void my_printf_unprintable(va_list *ap)
{
    my_putstr_unprintable(va_arg(*ap, char *));
}