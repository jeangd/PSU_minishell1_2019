/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printfbin.c
*/

#include "my.h"

void my_put_bin(unsigned int n)
{
    unsigned int nb = n;
    int div = 1;
    char *basebin = "01";

    for (; nb / div > 1; div *= 2);
        for (int i = 0; div > 0;  div /= 2) {
            i = nb / div;
            my_putchar(basebin[i]);
            nb -= (i * div);
        }
}

void my_printfbin(va_list *ap)
{
    my_put_bin(va_arg(*ap, int));
}