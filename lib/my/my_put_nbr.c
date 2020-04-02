/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

int my_putchar(char c);

int my_put_nbr(int n)
{
    long nb = n;
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