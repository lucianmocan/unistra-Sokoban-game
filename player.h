#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <stdio.h>
#include <stdlib.h>

/**
 * @enum Direction
 * @brief Des caractères représentant une certaine direction.
 */
enum Direction {
    TOP = 'w', ///< vers le haut
    LEFT = 'a', ///< vers la gauche
    RIGHT = 'd', ///< vers la droite
    BOTTOM = 's' ///< vers le bas
};

/** 
 * @struct Player player.h
 * @brief Une structure représentant les coordonées d'un joueur.
*/
typedef struct Player{
    int x; ///< la coordonnée x
    int y; ///< la coordonnée y
} Player;

/** 
 * @struct Goal player.h
 * @brief Une structure représentant les coordonées d'une cible.
*/
typedef struct Goal{
    int x; ///< la coordonnée x
    int y; ///< la coordonnée y
} Goal;

/** 
 * @struct StrGoals player.h
 * @brief Une structure contenant un tableau des cibles
 * le nombre d'éléments présents et la taille allouée.
*/
typedef struct StrGoals{
    Goal* arrayOfGoals; ///< pointeur vers un tableau des cibles
    int count; ///< le nombre d'éléments stockés dans le tableau
    int size; ///< la taille allouée du tableau arrayOfGoals
} StrGoals;

/** 
 * @struct Point player.h
 * @brief Une structure représentant les coordonées d'un point.
*/
typedef struct Point{
    int x; ///< la coordonnée x
    int y; ///< la coordonnée y
} Point;

#endif