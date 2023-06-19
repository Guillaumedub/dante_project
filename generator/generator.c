/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 
*/

#include "my.h"

void gen_perf_maze2(char **maze, liste *list, maze_t *maze_t)
{
    maze[list->premier->y][list->premier->x] = '*';
    maze_t->actual_x = list->premier->x;
    maze_t->actual_y = list->premier->y;
    int rand_digit[4] = {1, 2, 3, 4};
    melanger(rand_digit, 4);
    int path_found = 0;
    for (int i = 0; i < 4; i++) {
        if (rand_digit[i] == 1 && path_found == 0)
            path_found = go_right(maze, list, maze_t);
        if (rand_digit[i] == 2 && path_found == 0)
            path_found = go_down(maze, list, maze_t);
        if (rand_digit[i] == 3 && path_found == 0)
            path_found = go_left(maze, list, maze_t);
        if (rand_digit[i] == 4 && path_found == 0)
            path_found = go_up(maze, list, maze_t);
    }
    if (path_found == 0)
        supprimer(list);
}

void gen_perf_maze(char **maze, liste *list, maze_t *maze_t)
{
    insertion(list, maze_t->actual_x, maze_t->actual_y);
    while (list->premier != NULL) {
        gen_perf_maze2(maze, list, maze_t);
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
        return 84;
    liste *list = initialisation();
    maze_t maze_t;
    srand(time(NULL));
    char **maze = malloc_2d_array(atoi(argv[2]), atoi(argv[1]));
    fill_maze(maze, atoi(argv[2]) ,atoi(argv[1]));
    maze_t.len_x = strlen(maze[0]);
    maze_t.len_y = my_len_of_array(maze);
    maze_t.actual_x = rand() % atoi(argv[1]);
    maze_t.actual_y = rand() % atoi(argv[2]);
    gen_perf_maze(maze, list, &maze_t);
    connect_begin_end(maze, atoi(argv[1]), atoi(argv[2]));
    make_it_unperfect(argv, maze, atoi(argv[1]), atoi(argv[2]));
    my_show_maze(maze, atoi(argv[1]));
    free_array(maze, my_len_of_array(maze));
    free_list(list);
    return 0;
}
