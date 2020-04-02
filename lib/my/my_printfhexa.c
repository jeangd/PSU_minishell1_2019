/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printfhexa.c
*/

#include "my.h"

void my_put_hexa(unsigned int n)
{
    unsigned int nb = n;
    int div = 1;
    char *basehexa = "0123456789abcdef";

    for (; nb / div > 9; div *= 16);
        for (int i = 0; div > 0;  div /= 16) {
            i = nb / div;
            my_putchar(basehexa[i]);
            nb -= (i * div);
        }
}

void my_printfhexa(va_list *ap)
{
    my_put_hexa(va_arg(*ap, int));
}