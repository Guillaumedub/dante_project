/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** solver.c
*/

#include "my.h"

enum direction {UP = -10, RIGHT = -11, DOWN = -12, LEFT = -13};

void set_shortest_direction(int *direction, maze_t *m)
{
    int direction_x = m->len_x - m->actual_x;
    int direction_y = m->len_y - m->actual_y;
    if (direction_x > direction_y) {
        direction[0] = RIGHT;
        direction[1] = DOWN;
        direction[2] = UP;
        direction[3] = LEFT;
    } else {
        direction[0] = DOWN;
        direction[1] = RIGHT;
        direction[2] = LEFT;
        direction[3] = UP;
    }
}

int solve_maze3(char **maze, liste *list, maze_t *m, int direction_order[4])
{
    int path = 0;
    for (int i = 0; i < 4; i++) {
        if (direction_order[i] == RIGHT && path == 0)
            path = solve_right(maze, list, m);
        if (direction_order[i] == DOWN && path == 0)
            path = solve_down(maze, list, m);
        if (direction_order[i] == LEFT && path == 0)
            path = solve_left(maze, list, m);
        if (direction_order[i] == UP && path == 0)
            path = solve_up(maze, list, m);
    }
    return path;
}

int solve_maze(char **maze, liste *list, maze_t *m)
{
    m->actual_x = list->premier->x;
    m->actual_y = list->premier->y;
    maze[m->actual_y][m->actual_x] = ' ';
    if (m->actual_x == m->len_x && m->actual_y == m->len_y) {
        while (list->premier != NULL) {
            maze[list->premier->y][list->premier->x] = 'o';
            supprimer(list);
        }
        return 1;
    }
    int direction_order[4] = {0, 0, 0, 0};
    set_shortest_direction(direction_order, m);
    int path = solve_maze3(maze, list, m, direction_order);
    if (path == 0)
        supprimer(list);
    return 0;
}

int solve_maze2(char **maze, liste *list, maze_t *m)
{
    insertion(list, 0, 0);
    while (list->premier != NULL) {
        if (solve_maze(maze, list, m))
            return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    liste *list = initialisation();
    maze_t maze_t;
    char **maze = file_into_2d_array(argv[1]);
    maze_t.len_x = strlen(maze[0]) - 1;
    maze_t.len_y = my_len_of_array(maze) - 1;
    int is_possible = 0;
    if (maze[0][0] != 'X') {
        is_possible = solve_maze2(maze, list, &maze_t);
    }
    if (is_possible == 1) {
        get_only_true_path(maze, &maze_t);
        my_show_maze(maze, strlen(maze[0]));
    } else {
        printf("no solution found\n");
    }
    free_array(maze, my_len_of_array(maze));
    free_list(list);
    return 0;
}
