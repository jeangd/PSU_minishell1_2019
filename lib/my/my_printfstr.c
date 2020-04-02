/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putstr_base_2019
*/

#include <stdarg.h>
#include "my.h"
#include <unistd.h>

void my_printfstr(va_list *ap)
{
    char *str = va_arg(*ap, char *);

    write(1, str, my_strlen(str));
}