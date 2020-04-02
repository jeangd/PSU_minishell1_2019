/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_revstr.c
*/

#include <stdio.h>
#include <unistd.h>

int main(void);

char *my_revstr(char *str)
{
    char k;
    int h;
    int j;

    h = 0;
    while (str[h] != '\0')
        h++;
    j = -1;
    while (j <= h) {
        k = str[j];
        str[j] = str[h];
        str[h] = k;
        j++;
        h--;
    }
    return (str);
}
