/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_swap.c
*/

#include <unistd.h>
#include <stdio.h>

int my_putchar(char c);

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
