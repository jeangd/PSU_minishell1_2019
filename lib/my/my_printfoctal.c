/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printfoctal.c
*/

#include "my.h"

void my_put_octal(unsigned int n)
{
    unsigned int nb = n;
    int div = 1;
    char *baseoc = "01234567";

    for (; nb / div > 7; div *= 8);
        for (int i = 0; div > 0;  div /= 8) {
            i = nb / div;
            my_putchar(baseoc[i]);
            nb -= (i * div);
        }
}

void my_printfoctal(va_list *ap)
{
    my_put_octal(va_arg(*ap, int));
}