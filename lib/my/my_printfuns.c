/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printfuns.c
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>

int my_put_nbruns(unsigned int n)
{
    unsigned int nb = n;
    int div = 1;

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    for (; nb / div > 9; div *= 10);
        for (int i = 0; div > 0;  div /= 10) {
            i = nb / div;
            my_putchar(i + '0');
            nb -= (i * div);
        }
}

void my_printfuns(va_list *ap)
{
    my_put_nbruns(va_arg(*ap, int));
}