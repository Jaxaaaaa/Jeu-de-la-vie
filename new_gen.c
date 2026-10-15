#include "new_gen.h"
#include "cells.h"
void init_new_gen(int lines_nb, int cols_nb, Cell cells_new_gen[cols_nb][lines_nb]){
    for(int x = 0; x < cols_nb; x++){
        for(int y = 0; y < lines_nb; y++){
            cells_new_gen[x][y].alive = 0;
            cells_new_gen[x][y].width = CELL_SIZE;
            cells_new_gen[x][y].coord_x = x * CELL_SIZE;
            cells_new_gen[x][y].coord_y = y * CELL_SIZE;
            cells_new_gen[x][y].alive_nb = 0;
        }
    }
}

void update_new_gen(int lines_nb, int cols_nb, Cell cells_new_gen[cols_nb][lines_nb], Cell old_gen[cols_nb][lines_nb]){
    for(int x = 0; x < cols_nb; x++){
        for(int y = 0; y < lines_nb; y++){
            if(old_gen[x][y].alive == 1 && old_gen[x][y].alive_nb < 2){
                cells_new_gen[x][y].alive = 0;
            }
            else if(old_gen[x][y].alive == 1 && old_gen[x][y].alive_nb > 1 && old_gen[x][y].alive_nb < 4){
                cells_new_gen[x][y].alive = 1;
            }
            else if(old_gen[x][y].alive == 1 && old_gen[x][y].alive_nb >3){
                cells_new_gen[x][y].alive = 0;
            }
            else if(old_gen[x][y].alive == 0 && old_gen[x][y].alive_nb == 3){
                cells_new_gen[x][y].alive = 1;
            }
            else if(old_gen[x][y].alive == 0 && old_gen[x][y].alive_nb != 3){
                cells_new_gen[x][y].alive = 0;
            }
       }
    }
}