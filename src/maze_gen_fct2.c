/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 
*/

#include "my.h"

int go_right(char **maze, liste *list, maze_t *maze_t)
{
    if (maze_t->actual_x + 2 < maze_t->len_x) {
        if (maze[maze_t->actual_y][maze_t->actual_x + 2] == 'X') {
            maze[maze_t->actual_y][maze_t->actual_x + 1] = '*';
            insertion(list, list->premier->x + 2, list->premier->y);
            return 1;
        }
    }
    return 0;
}

int go_down(char **maze, liste *list, maze_t *maze_t)
{
    if (maze_t->actual_y + 2 < maze_t->len_y) {
        if (maze[maze_t->actual_y + 2][maze_t->actual_x] == 'X') {
            maze[maze_t->actual_y + 1][maze_t->actual_x] = '*';
            insertion(list, list->premier->x, list->premier->y + 2);
            return 1;
        }
    }
    return 0;
}

int go_up(char **maze, liste *list, maze_t *maze_t)
{
    if (maze_t->actual_y - 1 > 0) {
        if (maze[maze_t->actual_y - 2][maze_t->actual_x] == 'X') {
            maze[maze_t->actual_y - 1][maze_t->actual_x] = '*';
            insertion(list, list->premier->x, list->premier->y - 2);
            return 1;
        }
    }
    return 0;
}

int go_left(char **maze, liste *list, maze_t *maze_t)
{
    if (maze_t->actual_x - 1 > 0) {
        if (maze[maze_t->actual_y][maze_t->actual_x - 2] == 'X') {
            maze[maze_t->actual_y][maze_t->actual_x - 1] = '*';
            insertion(list, list->premier->x - 2, list->premier->y);
            return 1;
        }
    }
    return 0;
}
