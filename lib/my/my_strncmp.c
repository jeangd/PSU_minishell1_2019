/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int cmp = 0;

    for (int i = 0; n > 0; n--, i++, cmp++)
        if (s1[i] != s2[i])
            return (84);
    return (cmp);
}
