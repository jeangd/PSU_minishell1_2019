/*
** EPITECH PROJECT, 2019
** CPool_rush2_2019
** File description:
** my_str_isupper.c
*/

int my_str_isupper(char *str)
{
    for (; *str; ++str)
        if (!((*str > 64) && (*str <= 90)))
            return (0);
    return (1);
}
