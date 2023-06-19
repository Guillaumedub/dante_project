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

liste *initialisation(void)
{
    liste *liste = malloc(sizeof(*liste));
    liste->premier = NULL;
    return liste;
}

void insertion(liste *liste, int x, int y)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    nouveau->x = x;
    nouveau->y = y;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
    if (liste->premier->suivant == NULL)
        liste->dernier = liste->premier;
}

void supprimer(liste *liste)
{
    if (liste->premier != NULL) {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void show_liste(liste *liste)
{
    Element *actuel = liste->premier;
    while (actuel != NULL) {
        printf("x = %d, y = %d\n", actuel->x, actuel->y);
        actuel = actuel->suivant;
    }
}
