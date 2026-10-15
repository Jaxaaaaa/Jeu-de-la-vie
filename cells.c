#include "cells.h"
#include "raylib.h"
#include "new_gen.h"
void init_cell(int lines_nb, int cols_nb, Cell cells[cols_nb][lines_nb]){
    for(int x = 0; x < cols_nb; x++){
        for(int y = 0; y < lines_nb; y++){
            cells[x][y].alive = 0;
            cells[x][y].width = CELL_SIZE;
            cells[x][y].coord_x = x * CELL_SIZE;
            cells[x][y].coord_y = y * CELL_SIZE;
            cells[x][y].alive_nb = 0;
        }
    }
}

void place_cell(int lines_nb, int cols_nb, Cell cells[cols_nb][lines_nb]){
    int mouse_x = GetMouseX();
    int mouse_y = GetMouseY(); 
    for(int x = 0; x < cols_nb; x++){
        for(int y = 0; y < lines_nb; y++){
            if(cells[x][y].alive == 0 &&
                cells[x][y].coord_x < mouse_x &&
                mouse_x < cells[x][y].coord_x + cells[x][y].width &&
                cells[x][y].coord_y < mouse_y &&
                mouse_y < cells[x][y].coord_y + cells[x][y].width){
                cells[x][y].alive = 1;
            }
            else if(cells[x][y].alive == 1 &&
                cells[x][y].coord_x < mouse_x &&
                mouse_x < cells[x][y].coord_x + cells[x][y].width &&
                cells[x][y].coord_y < mouse_y &&
                mouse_y < cells[x][y].coord_y + cells[x][y].width){
                cells[x][y].alive = 0;
            }
        } 
    }
}

void update_cells(int lines_nb, int cols_nb, Cell cells[cols_nb][lines_nb], Cell new_gen[cols_nb][lines_nb]){
    for(int x = 0; x < cols_nb; x++){
        for(int y = 0; y < lines_nb; y++){
            cells[x][y].alive = new_gen[x][y].alive;
        }
    }   
}