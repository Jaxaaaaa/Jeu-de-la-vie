#ifndef NEW_GEN_H
#define NEW_GEN_H
#include "config.h"
#include "cells.h"
//Créer un tableau de cells_new_gen et l'intialisé avec alive à false
//Une fonction qui importe le tableau cells et le tableau
//Pour chaque cellule, appliquer la règle et la sauvegarder dans cells_new_gen
//Quand la boucle est terminée, copier cells_new_gen dans cells
void init_new_gen(int lines_nb, int cols_nb, Cell cells_new_gen[cols_nb][lines_nb]);
void update_new_gen(int lines_nb, int cols_nb, Cell cells_new_gen[cols_nb][lines_nb], Cell old_gen[cols_nb][lines_nb]);
#endif