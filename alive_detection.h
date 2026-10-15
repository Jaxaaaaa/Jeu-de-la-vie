#ifndef ALIVE_DETECTION_H
#define ALIVE_DETECTION_H
#include "config.h"
#include "cells.h"
//un compteur de cellules vivantes autour de chaque cellule
//il faut une fonction qui verifie si une cellule vivante a - de 2 voisines vivantes, si elle a 2 ou 3 voisines vivantes, ou si elle a plus de 3 voisines vivantes
//ou si une cellule est morte et qu'elle a 3 cellules vivantes

void how_many_neighbor_alive(int lines_nb, int cols_nb, int target_x, int target_y, Cell *target_cell, Cell tested_cells[cols_nb][lines_nb]);
#endif