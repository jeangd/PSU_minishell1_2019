/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strncat.c
*/

int main(void);

int my_strlen(char const *dest)
{
    int i = 0;
    while (dest[i])
        i++;
    return (i);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);
    int j = 0;

    for (j = 0; src[j] != '\0' && j < nb; j++)
        dest[i + j] = src[j];
    dest[j + i] = '\0';
    return (dest);
}
