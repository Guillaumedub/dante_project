/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-dante-guillaume.dubuis
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #define PI 3.14159
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ucontext.h>
    #include <math.h>
    #include <time.h>

typedef struct Element Element;
typedef struct Element {
    int x;
    int y;
    Element *suivant;
} Element;

typedef struct liste liste;
typedef struct liste {
    Element *premier;
    Element *dernier;
} liste;

typedef struct maze_t {
    int len_x;
    int len_y;
    int path_found;
    int actual_x;
    int actual_y;
} maze_t;

char **malloc_2d_array(int y, int x);
char **my_str_to_word_array(char *str, char delimiter);
int my_len_of_array(char **tab);
void reduce_len_of_str(char *dest, char *src, int reduce);
void free_array(char **array, int size);
void fill_maze(char **maze, int len_y ,int len_x);
void my_show_maze(char **tab, int x);
void gen_perf_maze(char **maze, liste *list, maze_t *maze_t);
void melanger(int *tab, int n);
int go_right(char **maze, liste *list, maze_t *maze_t);
int go_down(char **maze, liste *list, maze_t *maze_t);
int go_up(char **maze, liste *list, maze_t *maze_t);
int go_left(char **maze, liste *list, maze_t *maze_t);
void connect_begin_end(char **maze, int x, int y);
void make_it_unperfect(char **argv, char **maze, int x,int y);
void delete_return_of_line(char *line, int largeur);
char **file_into_2d_array(char *filepath);
int solve_right(char **maze, liste *list, maze_t *m);
int solve_down(char **maze, liste *list, maze_t *m);
int solve_up(char **maze, liste *list, maze_t *m);
int solve_left(char **maze, liste *list, maze_t *m);
int solve_maze(char **maze, liste *list, maze_t *maze_t);
void get_only_true_path2(char **maze, int x, int y);
void get_only_true_path(char **maze, maze_t *m);
liste *initialisation(void);
void insertion(liste *liste, int x, int y);
void supprimer(liste *liste);
void free_list(liste *liste);
int get_len(Element *actuel);
int solve_maze2(char **maze, liste *list, maze_t *m);

#endif
