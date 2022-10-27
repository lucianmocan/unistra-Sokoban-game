#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "player.h"


Grid move_player(Grid grid, enum Direction direction){

    int x = grid->player.x;
    int y = grid->player.y;

    switch(direction){
        case TOP: {
            enum CaseType tmp = grid->game_grid[y+1][x];
            if (!(tmp == WALL && tmp == BOX)){
                grid->game_grid[y+1][x] = PLAYER;
                grid->player.y = y+1;
            }
            break;
        }
        case BOTTOM: {
            enum CaseType tmp = grid->game_grid[y-1][x];
            if (!(tmp == WALL && tmp == BOX)){
                grid->game_grid[y-1][x] = PLAYER;
                grid->player.y = y-1;
            }
            break;
        }
        case LEFT: {
            enum CaseType tmp = grid->game_grid[y][x-1];
            if (!(tmp == WALL && tmp == BOX)){
                grid->game_grid[y][x-1] = PLAYER;
                grid->player.x = x-1;
            }
            break;
        }
        case RIGHT: {
            enum CaseType tmp = grid->game_grid[y][x+1];
            if (!(tmp == WALL && tmp == BOX)){
                grid->game_grid[y][x+1] = PLAYER;
                grid->player.x = x+1;
            }
            break;
        }
    }        
}

int main(){


    return 0;
}