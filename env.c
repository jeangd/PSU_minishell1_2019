/*
** EPITECH PROJECT, 2020
** PSU_minishell_2019
** File description:
** env.c
*/

#include "include/my.h"

int modif_env_unsetenv(shell_t *shell, int y, int nb, int z)
{
    if (shell->command[y + 1] == NULL)
        shell->command[y][my_strlen(shell->command[y]) - 1] = '\0';
    else
        shell->command[y][my_strlen(shell->command[y])] = '\0';
    if (my_strcmp(shell->command[0], "unsetenv") == 0) {
        z = search_in_env(shell, nb, y);
        if (z == (nb - 1))
            return (0);
        shell->env[z] = NULL;
        for (; shell->env[z] != NULL; z++)
        shell->env[z] = shell->env[z + 1];
    }
    shell->env[z] = NULL;
    return (0);
}

int search_in_env(shell_t *shell, int nb, int y)
{
    int z = 0;

    for (z = 0; my_strncmp(shell->env[z], shell->command[y],
        my_strlen(shell->command[y])) != my_strlen(shell->command[y]); z++) {
        if (z == (nb - 1))
            break;
        }
    return (z);
}

int check_letter_in_param(shell_t *shell, int i)
{
    if ((shell->command[1][0] < 'a' || shell->command[1][0] > 'z') &&
        (shell->command[1][0] < 'A' || shell->command[1][0] > 'Z')) {
        my_puterror(shell->command[0]);
        my_puterror(": Variable name must start with a letter.\n");
        return (0);
    }
    shell->command[1][my_strlen(shell->command[1]) - 1] = '\0';
    for (int z = 0; shell->command[1][z] != '\0'; z++)
        if ((shell->command[1][z] < 'a' || shell->command[1][z] > 'z') &&
            (shell->command[1][z] < 'A' || shell->command[1][z] > 'Z') &&
            (shell->command[1][z] < '0' || shell->command[1][z] > '9')) {
        my_puterror(shell->command[0]);
        my_puterror(": Variable name must contain alphanumeric");
        my_puterror(" characters.\n");
        return (0);
        }
    shell->env_cp[i] = my_strcat(shell->command[1], "=");
    return (0);
}