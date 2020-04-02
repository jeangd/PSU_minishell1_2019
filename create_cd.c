/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** create_cd.c
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int cd_back(shell_t *shell)
{
    chdir(shell->before_cd);
    return (0);
}

int cd_no_arg(shell_t *shel, char *racine)
{
    for (shel->e = 0, shel->nb_ch = 0; racine[shel->e] != '\0'; shel->e++)
        if (racine[shel->e] == '/')
            shel->nb_ch++;
    for (; shel->nb_ch > 2; shel->nb_ch--)
        chdir("../");
    return (0);
}

int make_cd(shell_t *shel)
{
    char *buffer = 0;
    size_t size = 0;
    char *racine = getcwd(buffer, size);

    for (shel->i = 0; shel->command[shel->i] != NULL; shel->i++);
    if (shel->i == 2 && shel->command[1][0] != '\n' &&
        shel->command[1][0] == '-')
        cd_back(shel);
    racine = getcwd(buffer, size);
    shel->before_cd = racine;
    if (shel->i == 1 || shel->command[1][0] == '\n') {
        cd_no_arg(shel, racine);
    }
    if (shel->i == 2 && shel->command[1][0] != '\n' &&
        shel->command[1][0] != '-') {
        shel->command[1][my_strlen(shel->command[1]) - 1] = '\0';
        if (chdir(shel->command[1]) == -1)
            perror("cd");
    }
    return (0);
}