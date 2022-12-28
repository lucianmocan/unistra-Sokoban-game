#include <stdbool.h>

#include "grid.h"
#include "player.h"

/**
 * @brief Fonction qui vérifie si un certain point représente un point cible.
 * 
 * @param grid Adresse d'une structure Grid.
 * @param p Une structure Point, coordonnées du point qu'on cherche à vérifier.
 * @return true Si p correspond à un point cible.
 * @return false Si p est un point autre qu'un point cible.
 */
bool checkIfPointIsGoal(Grid grid, Point p){
    for (int i = 0; i<grid->targets; i++){
        if (grid->goals.arrayOfGoals[i].x == p.x && grid->goals.arrayOfGoals[i].y == p.y){
            return true;
        }
    }
    return false;
}

/**
 * @brief Fonction qui aide à déterminer le plan de mouvement d'une direction.
 * 
 * @param direction Une direction de 4 possibles Direction.
 * @return int 1 si c'est le plan vertical, 0 si c'est le plan horizontal.
 */
int motionPlane(enum Event direction){
    int motn_plane;
    switch(direction){
        case Up :
        case Down : 
            motn_plane = 1;
            break;
        case Left :
        case Right :
            motn_plane = 0;
            break;
        case Quit:
        case None:
            printf("Error! This shouldn't happen!\n");
            exit(1);
    }
    return motn_plane;
}

/**
 * @brief Fonction qui met à jour la céllule précédant la position courante du joueur.
 * 
 * @param grid Adresse d'une structure Grid. 
 * @return Grid Adresse de la structure Grid avec la mise à jour de la céllule précedante.
 */
Grid updatePreviousCell(Grid grid){
    if (checkIfPointIsGoal(grid, (Point) {grid->player.x, grid->player.y})){
        grid->game_grid[grid->player.y][grid->player.x] = GOAL;
    }
    else {
        grid->game_grid[grid->player.y][grid->player.x] = NONE;
    }
    return grid;
}

/**
 * @brief Fonction qui met à jour la position courante du joueur.
 * 
 * @param grid Adresse d'une structure Grid.
 * @param c_1 Un Point contenant les coordonnées de la céllule suivante en dépendance du plan de mouvement
 * @param motn_plane Le plan de mouvement. Vertical si == 1, horizontal si == 0;
 * @return Grid Adresse de la structure Grid avec la mise à jour de la position courante du joueur.
 */
Grid updatePlayerPosition(Grid grid, Point c_1, int motn_plane){
    if (motn_plane)
        grid->player.y = c_1.y;
    else 
        grid->player.x = c_1.x;
    return grid;
}

/**
 * @brief Fonction qui réalise un mouvement dans une certaine diréction.
 * 
 * @param grid Adresse d'une structure Grid.
 * @param direction La direction du mouvement.
 * @param c_1 Un Point contenant les coordonnées de la céllule suivante.
 * @param c_2 Un Point contenant les coordonnées de la céllule suivant la céllule suivante.
 * @return Grid Adresse de la structure Grid modifiée représentant la réalisation du mouvement.
 */
Grid make_move(
            Grid grid, 
            enum Event direction, 
            Point c_1, 
            Point c_2
        )
    {
    int motn_plane = motionPlane(direction);
    enum CaseType val_cell_next_1 = grid->game_grid[c_1.y][c_1.x]; // valeur de la case c_1
    enum CaseType val_cell_next_2 = grid->game_grid[c_2.y][c_2.x]; // valeur de la case c_2
    enum CaseType* address_next_1 = &grid->game_grid[c_1.y][c_1.x]; // adresse de la case c_1
    enum CaseType* address_next_2 = &grid->game_grid[c_2.y][c_2.x]; // adresse de la case c_2
    if (val_cell_next_1 == BOX){
        if (val_cell_next_2 != WALL && !checkIfPointIsGoal(grid, c_1)){
            *address_next_1 = PLAYER;
            *address_next_2 = BOX;
            updatePreviousCell(grid);
            updatePlayerPosition(grid, c_1, motn_plane);
            if(val_cell_next_2 == GOAL){
                grid->covered_targets++;
            }
        }
    }
    else {
        if (!(val_cell_next_1 == WALL)){
            *address_next_1 = PLAYER;
            updatePreviousCell(grid);
            updatePlayerPosition(grid, c_1, motn_plane);
        }

    }
    return grid;
}

/**
 * @brief Fonction qui calcule les coordonnées des céllules
 * qui pourraient être impliquées dans le mouvement et les fournit à la fonction make_move().
 * 
 * @param grid Adresse d'une structure Grid.
 * @param direction La direction du mouvement.
 * @return Grid Adresse de la structure Grid modifiée représentant la réalisation du mouvement.
 */
Grid move_player(Grid grid, enum Event direction){

    int x = grid->player.x;
    int y = grid->player.y;
    switch(direction){
        case Up: {
            int pos_1 = y-1, pos_2 = pos_1 - 1;
            make_move(
                grid, 
                direction,  
                (Point){x, pos_1}, 
                (Point){x, pos_2}
            );
            break;
        }
        case Down: {
            int pos_1 = y+1, pos_2 = pos_1 + 1;
            make_move(
                grid, 
                direction, 
                (Point){x, pos_1}, 
                (Point){x, pos_2}
            );
            break;
        }
        case Left: {
            int pos_1 = x-1, pos_2 = pos_1 - 1;
            make_move(
                grid, 
                direction,  
                (Point){pos_1, y}, 
                (Point){pos_2, y}
            );
            break;
        }
        case Right: {
            int pos_1 = x+1, pos_2 = pos_1 + 1;
            make_move(
                grid, 
                direction, 
                (Point){pos_1, y}, 
                (Point){pos_2, y}
            );
            break;
        }
        case Quit:
        case None:
            printf("Error! This shouldn't happen!");
            exit(1);
    }    
    return grid;    
}
