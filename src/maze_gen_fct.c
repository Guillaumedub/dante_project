/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** dante's
*/

#include "my.h"

void fill_maze(char **maze, int len_y ,int len_x)
{
    for (int y = 0; y < len_y; y++) {
        int x = 0;
        for (x = 0; x < len_x; x++) {
            maze[y][x] = 'X';
        }
        maze[y][x] = '\0';
    }
}

void connect_begin_end(char **maze, int x, int y)
{
    if (maze[0][0] == 'X') {
        if (maze[1][0] == 'X' && maze[0][1] == 'X') {
            maze[0][0] = '*';
            maze[0][1] = '*';
        } else {
            maze[0][0] = '*';
        }
    }
    if (maze[y - 1][x - 1] == 'X') {
        if (maze[y - 2][x - 1] == 'X' && maze[y - 1][y - 2] == 'X') {
            maze[y - 1][x - 1] = '*';
            maze[y - 1][x - 2] = '*';
        } else {
            maze[y - 1][x - 1] = '*';
        }
    }
}

void melanger(int *tab, int n)
{
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
}

void make_it_unperfect(char **argv, char **maze, int x,int y)
{
    if (argv[3] != NULL) {
        if (strcmp(argv[3], "perfect") == 0) {
            return;
        }
    }
    int nbr_of_wall_sup = x * y / 7;
    for (; nbr_of_wall_sup > 0; nbr_of_wall_sup--) {
        int actual_x = rand() % x;
        int actual_y = rand() % y;
        if (maze[actual_y][actual_x] == 'X') {
            maze[actual_y][actual_x] = '*';
        }
    }
}
