#include "raylib.h"
#include <stdio.h>
#include "raymath.h"
#include "rlgl.h"
#include "config.h"
#include "cells.h"

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    int lines_nb = SCREEN_WIDTH / CELL_SIZE;
    int cols_nb = SCREEN_HEIGHT / CELL_SIZE;  
    int cases_nb = lines_nb * cols_nb;  
    Cell cells[lines_nb][cols_nb];
    init_cell(lines_nb, cols_nb, cells);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            place_cell(lines_nb, cols_nb, cells);
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
    for(int x = 0; x < lines_nb; x++){ //Draw rectangle if the cell is alive
        for(int y = 0; y < cols_nb; y++){
            if(cells[x][y].alive == 1){
                DrawRectangle(cells[x][y].coord_x, cells[x][y].coord_y, cells[x][y].width, cells[x][y].width, GREEN);
            }
        }
    }
        for(int x = 0 ; x < SCREEN_WIDTH; x += CELL_SIZE){ //draw rectangle lines
            for(int y = 0 ; y < SCREEN_HEIGHT; y += CELL_SIZE){
                DrawRectangleLines(x, y, CELL_SIZE, CELL_SIZE, BLACK);
                
            }
        }
        EndDrawing();
    }
return 1;
}