/*
** EPITECH PROJECT, 2019
** CPool_rush2_2019
** File description:
** my_str_islower.c
*/

int my_str_islower(char *str)
{
    for (; *str; ++str)
        if (!((*str > 96) && (*str <= 122)))
            return (0);
    return (1);
}
