/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "include/my.h"

int intialisation(shell_t *shell, char **av, char **env)
{
    UNUSED(av);
    shell->str = NULL;
    shell->command = NULL;
    shell->env_cp = NULL;
    shell->cwd = 0;
    if (env[0] == NULL)
        return (84);
    shell->env = env;
    return (0);
}

int search_path_cp_env(shell_t *shell)
{
    int i = 0;
    int j = 0;
    int z = 0;

    cp_env(shell);
    for (i = 0; shell->env[i][0] != 'P'
        || shell->env[i][1] != 'A' || shell->env[i][2] != 'T'; i++);
    for (j = 0; shell->env[i][j] != '='; j++);
    shell->path = malloc(sizeof(char) * my_strlen(shell->env[i]) - 4);
    if (shell->path == NULL)
        return (84);
    stock_path(shell, j, z, i);
    shell->word_tab = str_to_word_tab(shell->path, ':');
    for (unsigned int a = 0; shell->word_tab[a] != NULL; a++)
        shell->word_tab[a] = my_strcat(shell->word_tab[a], "/");
    for (unsigned int y = 0; shell->word_tab[y] != NULL; y++)
        if (access(shell->word_tab[y], F_OK) == 0)
            break;
    return (0);
}

int create_shell(shell_t *shell)
{
    for (size_t size = 0; 1;) {
        shell->print_env = 0;
        shell->str = NULL;
        my_printf("[%s] $>  ", getcwd(shell->cwd, size));
        if (getline(&shell->str, &shell->len, stdin) == -1) {
            free_all(shell);
            my_printf("exit\n");
            return (-1);
        }
        if (shell->str[0] != '\n') {
            str_correction(shell);
            clean(shell);
            if (building(shell) == -1)
                return (-1);
            if (shell->print_env == 0)
                other_fonctions(shell);
        }
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));
    if (shell == NULL)
        return (84);

    if (intialisation(shell, av, env) == 84)
        return (0);
    if (ac != 1)
        return (84);
    if (search_path_cp_env(shell) != 0)
        return (84);
    if (create_shell(shell) == -1)
        return (0);
    return (0);
}