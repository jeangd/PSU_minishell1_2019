/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** system_fonction.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "include/my.h"

int just_command(shell_t *shell)
{
    int i = 0;
    int j = 0;

    for (j = 0; shell->concat[j] != ' ' && shell->concat[j] != '\0'; j++);
    shell->name = malloc(sizeof(char) * j + 1);
    if (shell->name == NULL)
        return (84);
    for (i = 0; shell->concat[i] != ' ' && shell->concat[i] != '\0'; i++) {
        shell->name[i] = shell->concat[i];
    }
    shell->name[i] = '\0';
    return (0);
}

int system_fonction(shell_t *shell)
{
    int i = 0;

    for (int z = 0; shell->command[z] != NULL; z++)
        if (shell->command[z][my_strlen(shell->command[z]) - 1] == '\n')
            shell->command[z][my_strlen(shell->command[z]) - 1] = '\0';
        else
            shell->command[z][my_strlen(shell->command[z])] = '\0';
    for (; shell->word_tab[i]; i++) {
        shell->concat = my_strcat(shell->word_tab[i], shell->str);
        if (shell->concat[my_strlen(shell->concat) - 1] == '\n')
            shell->concat[my_strlen(shell->concat) - 1] = '\0';
        else
            shell->concat[my_strlen(shell->concat)] = '\0';
        just_command(shell);
        if (access(shell->name, F_OK) == 0)
            return (0);
    }
    return (0);
}