/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_compute_square_root.c
*/

int my_compute_square_root(int nb)
{
    int n = 1;
    int p = 0;

    for (;n != p && n <= nb;) {
        p = nb / n;
        if (n != p)
            n++;
    }
    if (n * p != nb)
        return (0);
    return (p);
}
