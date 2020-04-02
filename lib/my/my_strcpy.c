/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strncpy.c
*/

#include <unistd.h>
#include <stdio.h>

int main(void);

char *my_strcpy(char *dest, char const *src)
{
    int j;

    for (j = 0; src[j] != '\0'; j++)
        dest[j] = src[j];
    dest[j] = '\0';
    return (dest);
}
