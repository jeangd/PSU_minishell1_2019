/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** free.c
*/

#include "include/my.h"
#include <stdlib.h>

void free_all(shell_t *shell)
{
    free(shell->str);
    free(shell->path);
    for (int i = 0; shell->word_tab[i]; i++)
        free(shell->word_tab[i]);
    free(shell);
}