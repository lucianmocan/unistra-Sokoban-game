
#include "grid.h"
#include "player.h"




void make_move(
            Grid grid, 
            enum Direction direction, 
            int next, 
            enum CaseType* tmp_1, 
            enum CaseType* tmp_2, 
            int motn_plane
        )
    {
    enum CaseType t1 = *tmp_1;
    enum CaseType t2 = *tmp_2;
    if (!(t1 == WALL)){
        if (t1 == BOX){
            if(t2 != WALL){
                *tmp_2 = BOX;
                if(t2 == GOAL){
                    grid->count_targets++;
                }
            }
        }
        if (!(*tmp_2 == WALL && *tmp_1 == BOX)){
            *tmp_1 = PLAYER;
            grid->game_grid[grid->player.y][grid->player.x] = NONE;
            if (motn_plane)
                grid->player.y = next;
            else 
                grid->player.x = next;
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
                pos_1, 
                &grid->game_grid[pos_1][x],
                &grid->game_grid[pos_2][x],
                1
            );
            break;
        }
        case BOTTOM: {
            int pos_1 = y+1, pos_2 = pos_1 + 1;
            make_move(
                grid, 
                direction, 
                pos_1, 
                &grid->game_grid[pos_1][x],
                &grid->game_grid[pos_2][x],
                1
            );
            break;
        }
        case LEFT: {
            int pos_1 = x-1, pos_2 = pos_1 - 1;
            make_move(
                grid, 
                direction, 
                pos_1, 
                &grid->game_grid[y][pos_1],
                &grid->game_grid[y][pos_2],
                0
            );
            break;
        }
        case RIGHT: {
            int pos_1 = x+1, pos_2 = pos_1 + 1;
            make_move(
                grid, 
                direction, 
                pos_1, 
                &grid->game_grid[y][pos_1],
                &grid->game_grid[y][pos_2],
                0
            );
            break;
        }
    }    
    return grid;    
}


// int main(){


//     return 0;
// }