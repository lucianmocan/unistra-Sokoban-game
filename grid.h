#ifndef GRID_HEADER
#define GRID_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "player.h"


enum CaseType{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' '
};
/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
typedef struct Grid{
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nomber de ligne de game_grid
	int targets; ///Number of targets on the map
	int count_targets; ///Number of targets covered
	Player player;
	Goals goals; // array containing the goals and their coordinates
} *Grid, str_grid;

Grid init_level(const char* file_path);

Grid move_player(Grid grid, enum Direction direction);

Grid move_player(Grid grid, enum Direction direction);

void affiche_niveau(Grid grid);

bool checkIfDone(Grid grid);

void freeGrid(Grid grid);

#endif
