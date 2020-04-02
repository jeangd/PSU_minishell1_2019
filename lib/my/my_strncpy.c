/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strncpy.c
*/

int main(void);

int my_strlen(char const *src);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = n;

    for (i = 0; i < n; i++)
        dest[i] = src[i];
    dest[i] == '\0';
    return (dest);
}
