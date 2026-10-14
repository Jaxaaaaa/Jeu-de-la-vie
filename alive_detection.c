#include "cells.h"
#include "alive_detection.h"
#include "raylib.h"

void set_neighbors_state(Cells_around cells_around, Cell target_cell, int lines_nb, int cols_nb, Cell cells[lines_nb][cols_nb]){
    int target_x = target_cell.coord_x;
    int target_y = target_cell.coord_y;
    for(x = -1; x < 1; x++){
        for(y = -1; y < 1; y++){
            cells[target_x + x][target_y + y].a
        }
    }