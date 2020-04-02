/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strstr.c
*/

#include <unistd.h>
#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    int j;

    if (str[0] != '\0') {
        for (j = 0; to_find[j] != '\0'; j++)
            if (to_find[j] != str[j])
                return (my_strstr((str + 1), to_find));
        return (str);
    }
    else
        return (0);
}
