#ifndef GRID_HEADER
#define GRID_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "player.h"

/**
 * @enum CaseType
 * @brief Des caractères représentant un certain type de céllule du game_grid.
 */
enum CaseType{
	WALL = '#', ///< représente un mur
	BOX = '$', ///< représente une boîte
	PLAYER = '@', ///< représente un joueur
	GOAL = '.', ///< représente une cible
	NONE = ' ' ///< représente une céllule vide
};

/**
 * @enum Event
 * @brief Des actions que l'on peut effectuer dans le jeu.
 */
enum Event {
  Quit='q', ///< quitter le programme
  Left=LEFT, ///< vers la gauche
  Right=RIGHT, ///< vers la droite
  Up=TOP, ///< vers le haut
  Down=BOTTOM, ///< vers le bas
  None ///< on fait rien
};

/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
typedef struct Grid{
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid.
	int row_number; ///< Nomber de ligne de game_grid.
	int targets; ///<Nombre des cibles présentes dans le game_grid.
	int covered_targets; ///<Nombre des cibles couvertes.
	Player player; ///<La position courante du joueur.
	StrGoals goals; ///< array containing the goals and their coordinates
} *Grid, str_grid;


Grid init_level(const char* file_path);

Grid move_player(Grid grid, enum Event direction);

void display_level(Grid grid);

bool checkIfDone(Grid grid);

void freeGrid(Grid grid);

bool checkIfPointIsGoal(Grid grid, Point p);

enum Event event();

#endif
