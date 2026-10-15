#include "raylib.h"
#include <stdio.h>
#include "raymath.h"
#include "rlgl.h"
#include "config.h"
#include "cells.h"
#include "alive_detection.h"

int main() {
    int lines_nb = SCREEN_HEIGHT / CELL_SIZE;
    int cols_nb = SCREEN_WIDTH / CELL_SIZE;
    int cases_nb = lines_nb * cols_nb;  
    Cell cells[cols_nb][lines_nb];
    init_cell(lines_nb, cols_nb, cells);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60);  

    while (!WindowShouldClose())    
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            place_cell(lines_nb, cols_nb, cells);
        }
        for(int x = 0; x< cols_nb; x++){
            for(int y = 0; y < lines_nb; y++){
                how_many_neighbor_alive(lines_nb, cols_nb, x, y, &cells[x][y], cells);
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
    for(int x = 0; x < cols_nb; x++){ //Draw rectangle if the cell is alive
        for(int y = 0; y < lines_nb; y++){
            if(cells[x][y].alive == 1){
                DrawRectangle(cells[x][y].coord_x, cells[x][y].coord_y, cells[x][y].width, cells[x][y].width, GREEN);
            }
            DrawText(TextFormat("%d", cells[x][y].alive_nb), cells[x][y].coord_x +5, cells[x][y].coord_y+5, 20, BLACK);
        }
    }
        for(int x = 0 ; x < SCREEN_WIDTH; x += CELL_SIZE){ //draw rectangle lines
            for(int y = 0 ; y < SCREEN_HEIGHT; y += CELL_SIZE){
                DrawRectangleLines(x, y, CELL_SIZE, CELL_SIZE, BLACK);
                
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}