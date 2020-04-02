/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_is_prime.c
*/

int my_is_prime(int nb)
{
    int res = nb - 1;

    if (nb == 1 || nb == 0)
        return (0);
    while (nb % res > 0)
        res--;
    if (res == 1)
        return (1);
    else
        return (0);
}
