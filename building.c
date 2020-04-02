/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** building.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "include/my.h"

void clean(shell_t *shell)
{
    for (int y = 0; shell->str[y] != '\0'; y++)
        if (shell->str[y] == '\t')
            shell->str[y] = ' ';
}

int building(shell_t *shell)
{
    shell->command = str_to_word_tab(shell->str, ' ');
    if (my_strcmp(shell->command[0], "cd\n") == 0 ||
        my_strcmp(shell->command[0], "cd") == 0) {
        if (make_cd(shell) == 0) {
            shell->print_env++;
            return (0);
        }
    }
    if (env_and_exit(shell) == 84)
        return (-1);
    return (0);
}

void str_correction(shell_t *shell)
{
    int i = 0;
    int u = 0;

    for (i = 0; shell->str[i] == ' ' || shell->str[i] == '\t'; i++);
    char *tmp = malloc(sizeof(char) * my_strlen(shell->str) - i + 1);
    for (u = 0; shell->str[i] != '\0' && shell->str[i] != '\n'; u++, i++)
        tmp[u] = shell->str[i];
    tmp[u] = '\n';
    tmp[u + 1] = '\0';
    shell->str = tmp;
}

int other_fonctions(shell_t *shell)
{
    int child = fork();

    shell->command = str_to_word_tab(shell->str, ' ');
    if (child == 0) {
        shell->str[my_strlen(shell->str) - 1] = '\0';
        system_fonction(shell);
        if (execve(shell->name, shell->command, shell->env) == -1)
            my_printf("%s: Command not found.\n", shell->command[0]);
    }
    else
        wait(&child);
    return (0);
}

void stock_path(shell_t *shell, int j, int z, int i)
{
    j++;
    for (z = 0; shell->env[i][j] != '\0'; z++, j++)
        shell->path[z] = shell->env[i][j];
    shell->path[z] = '\0';
}