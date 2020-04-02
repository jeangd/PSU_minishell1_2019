/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_putstr.c
*/

#include <unistd.h>

int my_putchar(char c);

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
