/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_getnbr.c
*/

#include <unistd.h>

long check_ab(int y, long c)
{
    if (c == 0)
        return (0);
    if (c > 2147483648)
        return (0);
    if (y == -1)
        c *= -1;
    if (c < -2147483648 || c > 2147483647)
        return (0);
    return (c);
}

int my_getnbr(char const *str)
{
    int z = 0;
    long c = 0;
    int y = 1;

    for (int i = 0; z != 1 && str[i] != '\0'; i++) {
        for (;str[i] >= '0' && str[i] <= '9'; i++) {
            for (int n = i-1; z == 0 && n >= 0 &&
                (str[n] == '-' || str[n] == '+'); n--)
                (str[n] == '-') ? y *= -1 : 0;
            c *= 10;
            c += (str[i] - '0');
            z = 1;
        }
    }
    return (check_ab(y, c));
}