/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printfnbr.c
*/

#include <stdarg.h>
#include "my.h"

void my_printfnbr(va_list *ap)
{
    my_put_nbr(va_arg(*ap, int));
}