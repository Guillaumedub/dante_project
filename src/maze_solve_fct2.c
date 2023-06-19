/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** maze
*/

#include "my.h"

int solve_right(char **maze, liste *list, maze_t *m)
{
    if (m->actual_x + 1 < m->len_x + 1) {
        if (maze[m->actual_y][m->actual_x + 1] == '*') {
            insertion(list, list->premier->x + 1, list->premier->y);
            return 1;
        }
    }
    return 0;
}

int solve_down(char **maze, liste *list, maze_t *m)
{
    if (m->actual_y + 1 < m->len_y + 1) {
        if (maze[m->actual_y + 1][m->actual_x] == '*') {
            insertion(list, list->premier->x, list->premier->y + 1);
            return 1;
        }
    }
    return 0;
}

int solve_up(char **maze, liste *list, maze_t *m)
{
    if (m->actual_y - 1 >= 0) {
        if (maze[m->actual_y - 1][m->actual_x] == '*') {
            insertion(list, list->premier->x, list->premier->y - 1);
            return 1;
        }
    }
    return 0;
}

int solve_left(char **maze, liste *list, maze_t *m)
{
    if (m->actual_x - 1 >= 0) {
        if (maze[m->actual_y][m->actual_x - 1] == '*') {
            insertion(list, list->premier->x - 1, list->premier->y);
            return 1;
        }
    }
    return 0;
}
