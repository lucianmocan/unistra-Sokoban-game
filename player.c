
#include <stdbool.h>

#include "grid.h"
#include "player.h"


bool checkIfPointIsGoal(Grid grid, Point p){
    for (int i = 0; i<grid->targets; i++){
        if (grid->goals.arrayOfGoals[i].x == p.x && grid->goals.arrayOfGoals[i].y == p.y){
            return true;
        }
    }
    return false;
}

int motionPlane(enum Direction direction){
    int motn_plane;
    switch(direction){
        case TOP :
        case BOTTOM : 
            motn_plane = 1;
            break;
        case LEFT :
        case RIGHT :
            motn_plane = 0;
            break;
    }
    return motn_plane;
}

void updatePreviousCell(Grid grid){
    if (checkIfPointIsGoal(grid, (Point) {grid->player.x, grid->player.y})){
        grid->game_grid[grid->player.y][grid->player.x] = GOAL;
    }
    else {
        grid->game_grid[grid->player.y][grid->player.x] = NONE;
    }
}

void updatePlayerPosition(Grid grid, Point c_1, int motn_plane){
    if (motn_plane)
        grid->player.y = c_1.y;
    else 
        grid->player.x = c_1.x;
}

void make_move(
            Grid grid, 
            enum Direction direction, 
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
                grid->count_targets++;
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
}

Grid move_player(Grid grid, enum Direction direction){

    int x = grid->player.x;
    int y = grid->player.y;

    switch(direction){
        case TOP: {
            int pos_1 = y-1, pos_2 = pos_1 - 1;
            make_move(
                grid, 
                direction,  
                (Point){x, pos_1}, 
                (Point){x, pos_2}
            );
            break;
        }
        case BOTTOM: {
            int pos_1 = y+1, pos_2 = pos_1 + 1;
            make_move(
                grid, 
                direction, 
                (Point){x, pos_1}, 
                (Point){x, pos_2}
            );
            break;
        }
        case LEFT: {
            int pos_1 = x-1, pos_2 = pos_1 - 1;
            make_move(
                grid, 
                direction,  
                (Point){pos_1, y}, 
                (Point){pos_2, y}
            );
            break;
        }
        case RIGHT: {
            int pos_1 = x+1, pos_2 = pos_1 + 1;
            make_move(
                grid, 
                direction, 
                (Point){pos_1, y}, 
                (Point){pos_2, y}
            );
            break;
        }
    }    
    return grid;    
}


// int main(){


//     return 0;
// }