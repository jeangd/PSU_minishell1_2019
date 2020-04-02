/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printchar.c
*/

#include <stdarg.h>
#include "my.h"
#include <unistd.h>

void my_printfchar(va_list *ap)
{
    char c = va_arg(*ap, int);

    write(1, &c, 1);
}