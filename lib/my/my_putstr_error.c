/*
** EPITECH PROJECT, 2020
** lib/my
** File description:
** my_putstr_error.c
*/

#include <unistd.h>
#include "my.h"

int my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
}