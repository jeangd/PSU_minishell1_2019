/*
** EPITECH PROJECT, 2020
** str
** File description:
** str_to_word_array
*/

#include "my.h"
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

static int count_nb_lign(const char *board, char a)
{
    int i = 0;

    for (int j = 0; board[j] != '\0'; j++)
        if (board[j] != a && (board[j + 1] == a || board[j + 1] == '\0'))
            i++;
    return (i);
}

int count_size_of_lign(char *board, char a)
{
    int i = 0;

    for (; board[i] == a; i++);
    for (; board[i] != a && board[i] != '\0'; i++);
    return (i);
}

int count_lign(char *board, char a)
{
    int i = 0;

    for (; board[i] == a; i++);
    for (; board[i] != a && board[i] != '\0'; i++);
    return (i);
}

char *fill(char *board, char *map, char a)
{
    int i = 0;
    int j = 0;

    for (; board[i] == a; i++);
    for (; board[i] != a && board[i] != '\0'; i++, j++)
        map[j] = board[i];
    map[j] = '\0';
    return (map);
}

char **str_to_word_tab(char *board, char a)
{
    char **map = NULL;
    int i = 0;
    const int nb_lign = count_nb_lign(board, a);

    map = malloc(sizeof(char *) * (nb_lign + 1));
    if (map == NULL)
        return (NULL);
    for (; i != nb_lign; i++) {
        map[i] = malloc(sizeof(char) * (count_size_of_lign(board, a) + 1));
        if (map[i] == NULL)
            return (NULL);
        map[i] = fill(board, map[i], a);
        board = board + count_lign(board, a);
    }
    map[i] = NULL;
    return (map);
}