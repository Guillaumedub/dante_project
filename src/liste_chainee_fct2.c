/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-dante-guillaume.dubuis
** File description:
** fonction.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int get_len(Element *actuel)
{
    int maxlen = 0;
    while (actuel != NULL) {
        maxlen++;
        actuel = actuel->suivant;
    }
    return maxlen;
}

void free_list(liste *liste)
{
    int len = get_len(liste->premier);
    for (int i = 0; i < len; i++) {
        supprimer(liste);
    }
    free(liste);
}
