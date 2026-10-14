#ifndef ALIVE_DETECTION_H
#define ALIVE_DETECTION_H
#include "config.h"
#include "cells.h"
//un compteur de cellules vivantes autour de chaque cellule
//il faut une fonction qui verifie si une cellule vivante a - de 2 voisines vivantes, si elle a 2 ou 3 voisines vivantes, ou si elle a plus de 3 voisines vivantes
//ou si une cellule est morte et qu'elle a 3 cellules vivantes
typedef enum{
    TOP_LEFT,
    TOP_MIDDLE,
    TOP_RIGHT,
    MIDDLE_LEFT,
    MIDDLE_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_MIDDLE,
    BOTTOM_RIGHT,
} Cells_around;
int how_many_neighbor_alive(Cells_around cells_around, Cell target_cell, int lines_nb, int cols_nb, Cell cells[lines_nb][cols_nb]);
#endif