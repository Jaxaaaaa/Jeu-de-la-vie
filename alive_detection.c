#include "cells.h"
#include "alive_detection.h"
#include "raylib.h"
//Passer la cellule testée à la fonction
//Tester chaque cellule autour et compter quand elle est alive
//Return le nombre de alive
void how_many_neighbor_alive(int lines_nb, int cols_nb, int target_x, int target_y, Cell *target_cell, Cell tested_cells[cols_nb][lines_nb]){
    int count = 0;
    for(int x = -1; x < 2 && target_x + x < cols_nb; x++){
        if(target_x + x < 0){
            continue;
        }
        for(int y = -1; y < 2 && target_y + y < lines_nb; y++){
            if(target_y +y < 0){
                continue; 
            }
            if(x == 0 && y == 0){
                continue;
            }
            if(tested_cells[target_x + x][target_y + y].alive){
                 count++;
            }
        }
    }
    target_cell->alive_nb = count;
}