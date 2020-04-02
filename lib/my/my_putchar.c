/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_putchar.c
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

