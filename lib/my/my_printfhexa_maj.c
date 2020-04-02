/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printfHEXA.c
*/

#include "my.h"

void my_put_caps_hexa(unsigned int n)
{
    unsigned int nb = n;
    int div = 1;
    char *baseHEXA = "0123456789ABCDEF";

    for (; nb / div > 9; div *= 16);
        for (int i = 0; div > 0;  div /= 16) {
            i = nb / div;
            my_putchar(baseHEXA[i]);
            nb -= (i * div);
        }
}

void my_printfcaps_hexa(va_list *ap)
{
    my_put_caps_hexa(va_arg(*ap, int));
}