#include "cells.h"
#include "alive_detection.h"
#include "raylib.h"

int how_many_neighbor_alive(Cells_around cells_around, Cell target_cell, int lines_nb, int cols_nb, Cell cells[lines_nb][cols_nb]){
    int target_x = target_cell.coord_x;
    int target_y = target_cell.coord_y;
    int count = 0;
    for(int x = -1; x < 1; x++){
        for(int y = -1; y < 1; y++){
            if(cells[target_x + x][target_y + y].alive && (cells[target_x] != 0 && cells[target_y] !=0)){
                count++;
            }
        }
    }
}