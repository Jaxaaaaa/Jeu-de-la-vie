#include "cells.h"

void init_cell(int lines_nb, int cols_nb, Cell cells[lines_nb][cols_nb]){
    for(int x = 0; x < lines_nb; x++){
        for(int y = 0; y < cols_nb; y++){it
            cells[x][y].alive = 1;
            cells[x][y].width = CELL_SIZE;
            cells[x][y].coord_x = x * CELL_SIZE;
            cells[x][y].coord_y = y * CELL_SIZE;
        }
    }
}
