/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_strlen.c
*/

#include <unistd.h>

int my_putchar(char c);

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
