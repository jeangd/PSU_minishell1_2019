/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printfpoint.c
*/

#include "my.h"

void my_printfpoint(va_list *ap)
{
    my_putstr("0x");
    my_put_hexa(va_arg(*ap, int));
}