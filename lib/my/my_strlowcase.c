/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strlowcase.c
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    return (str);
}
