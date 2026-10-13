#ifndef CELLS_H
#define CELLS_H
#include "config.h"
//chaque cellule a besoin de coordonées x et y pour savoir ou elle se trouve sur la grille
//chaqu cellule a besoin de alive pour savoir si elle est en vie
//chaque cellule a besoin d'une largeur et longeur 
//chaque cellule a besoin d'une couleur
typedef struct{
    int coord_x;
    int coord_y;
    int width;
    int alive;
} Cell; 

void init_cell(int lines_nb, int cols_nb, Cell cells[lines_nb][cols_nb]);
#endif