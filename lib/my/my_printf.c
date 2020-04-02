/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include "my.h"
#include "struct.h"

void flag(char s, va_list *ap)
{
    for (int j = 0; tabflag[j].flag != -1; j++) {
        if (tabflag[j].flag == s)
            tabflag[j].ptr(ap);
    }
}

void my_printf(char *s, ...)
{
    va_list ap;

    va_start(ap, s);
    for (int j = 0; s[j] != '\0'; j++) {
        if (s[j] == '%') {
            flag(s[j + 1], &ap);
            j++;
        }
        else if (s[j] != '%') {
            my_putchar(s[j]);
        }
    }
    va_end(ap);
}
