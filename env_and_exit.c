/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** env_and_exit.c
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

int setenv_with_twoarg(shell_t *shell, int i)
{
    int j = 0;

    for (i = 0; shell->env_cp[i] != NULL; i++);
    for (j = 0; shell->command[j] != NULL; j++);
    if (j > 3) {
        my_puterror("Too many arguments.\n");
        return (0);
    }
    shell->env_cp = malloc(sizeof(char *) * (i + 1));
    if (shell->env_cp == NULL)
        return (84);
    cp_env(shell);
    shell->command[1][my_strlen(shell->command[1])] = '\0';
    shell->env_cp[i] = my_strcat(shell->command[1], "=");
    shell->command[1][my_strlen(shell->command[2]) - 1] = '\0';
    shell->env_cp[i] = my_strcat(shell->env_cp[i], shell->command[2]);
    shell->env_cp[i][my_strlen(shell->env_cp[i]) - 1] = '\0';
    shell->env_cp[i + 1] = 0;
    shell->env = shell->env_cp;
    return (0);
}

int make_unsetenv(shell_t *shell)
{
    int i = 0;
    int nb = 0;
    int z = 0;

    shell->print_env++;
    for (i = 0; shell->command[i] != NULL; i++);
    if (i == 1) {
        my_puterror("unsetenv: Too few arguments.\n");
        return (0);
    }
    for (int y = 1; shell->command[y] != NULL; y++) {
        for (nb = 0; shell->env[nb] != NULL; nb++);
        modif_env_unsetenv(shell, y, nb, z);
    }
    return (0);
}

int make_setenv(shell_t *shell)
{
    int i = 0;
    shell->print_env++;

    if (shell->command[1] == NULL || shell->command[1][0] == '\n') {
        for (int u = 0; shell->env_cp[u] != NULL; u++)
            my_printf("%s\n", shell->env_cp[u]);
        return (0);
    }
    if (shell->command[2] == NULL || shell->command[2][0] == '\n')
        if (shell->command[1] != NULL || shell->command[1][0] != '\n') {
            for (i = 0; shell->env_cp[i] != NULL; i++);
            cp_env(shell);
            check_letter_in_param(shell, i);
            shell->env = shell->env_cp;
            return (0);
        }
    if (shell->command[2] != NULL || shell->command[2][0] != '\n')
        setenv_with_twoarg(shell, i);
    return (0);
}

int env_and_exit(shell_t *shell)
{
    if (my_strcmp(shell->str, "exit\n") == 0) {
        free_all(shell);
        my_printf("exit\n");
        exit (0); }
    if (my_strcmp(shell->str, "env\n") == 0) {
        for (int u = 0; shell->env[u] != NULL; u++)
            my_printf("%s\n", shell->env[u]);
        shell->print_env++;
        return (0);
    }
    shell->command = str_to_word_tab(shell->str, ' ');
    if (my_strcmp(shell->command[0], "setenv\n") == 0 ||
        my_strcmp(shell->command[0], "setenv") == 0) {
        make_setenv(shell);
        return (0);
    }
    if (my_strcmp(shell->command[0], "unsetenv\n") == 0 ||
        my_strcmp(shell->command[0], "unsetenv") == 0)
        make_unsetenv(shell);
    return (0);
}

char cp_env(shell_t *she)
{
    int i = 0;
    int j = 0;

    for (i = 0; she->env[i] != NULL; i++);
    she->env_cp = malloc(sizeof(char *) * (i + 2));
    if (she->env_cp == NULL)
        return (84);
    for (j = 0; j != i; j++) {
        she->env_cp[j] = malloc(sizeof(char) * (my_strlen(she->env[j]) + 1));
        if (she->env_cp[j] == NULL)
            return (84);
    }
    she->env_cp[j] = 0;
    for (unsigned int z = 0; she->env[z] != NULL; z++)
        for (unsigned int y = 0; she->env[z][y] != '\0'; y++)
            she->env_cp[z][y] = she->env[z][y];
    return (84);
}