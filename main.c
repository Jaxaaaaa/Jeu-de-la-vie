#include "raylib.h"
#include <stdio.h>
#include "raymath.h"
#include "rlgl.h"
#include "config.h"
#include "cells.h"
#include "alive_detection.h"
#include "new_gen.h"
#include "game.h"
int main() {
    int lines_nb = SCREEN_HEIGHT / CELL_SIZE;
    int cols_nb = SCREEN_WIDTH / CELL_SIZE;
    int cases_nb = lines_nb * cols_nb;  
    Cell cells[cols_nb][lines_nb];
    Cell cells_new_gen[cols_nb][lines_nb];
    init_cell(lines_nb, cols_nb, cells);
    init_new_gen(lines_nb, cols_nb, cells_new_gen);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60);
    int change_timer = CHANGE_DELAY;
    Game_state state = STATE_PLACING;

    while (!WindowShouldClose())    
    {
        switch (state)
        {
        case STATE_PLACING:
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(TextFormat("Cliquez pour placer une case"), 0, 0, 20, BLACK);
            DrawText(TextFormat("Appuyez sur espace pour lancer la simulation"), 0, 30, 20, BLACK);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                place_cell(lines_nb, cols_nb, cells);
            }
            for(int x = 0; x < cols_nb; x++){ //Draw rectangle if the cell is alive
                for(int y = 0; y < lines_nb; y++){
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
            if(IsKeyPressed(KEY_SPACE)){
                state = STATE_PLAYING;
            }
            break;
        case STATE_PLAYING:
            for(int x = 0; x< cols_nb; x++){
                for(int y = 0; y < lines_nb; y++){
                    how_many_neighbor_alive(lines_nb, cols_nb, x, y, &cells[x][y], cells);
                }
            }
            if(change_timer == 0){
                update_new_gen(lines_nb, cols_nb, cells_new_gen, cells);
                update_cells(lines_nb, cols_nb, cells, cells_new_gen);
                change_timer = CHANGE_DELAY; 
            }
            change_timer--;
            BeginDrawing();
            ClearBackground(RAYWHITE);
            for(int x = 0; x < cols_nb; x++){ //Draw rectangle if the cell is alive
                for(int y = 0; y < lines_nb; y++){
                    if(cells[x][y].alive == 1){
                        DrawRectangle(cells[x][y].coord_x, cells[x][y].coord_y, cells[x][y].width, cells[x][y].width, GREEN);
                    }
                }
            }
            EndDrawing();
            if(IsKeyPressed(KEY_SPACE)){
                state = STATE_PLACING;
            }
            break;
        }
    }
    CloseWindow();
    return 0;
}