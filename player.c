
#include "grid.h"
#include "player.h"

Grid move_player(Grid grid, enum Direction direction){

    int x = grid->player.x;
    int y = grid->player.y;

    switch(direction){
        case TOP: {
            enum CaseType tmp = grid->game_grid[y-1][x];
            printf("%c\n", tmp);
            if (!(tmp == WALL || tmp == BOX)){
                grid->game_grid[y-1][x] = PLAYER;
                grid->game_grid[y][x] = NONE;
                grid->player.y = y-1;
            }
            break;
        }
        case BOTTOM: {
            enum CaseType tmp = grid->game_grid[y+1][x];
            printf("%c\n", tmp);
            if (!(tmp == WALL || tmp == BOX)){
                grid->game_grid[y+1][x] = PLAYER;
                grid->game_grid[y][x] = NONE;
                grid->player.y = y+1;
            }
            break;
        }
        case LEFT: {
            enum CaseType tmp = grid->game_grid[y][x-1];
            printf("%c\n", tmp);
            if (!(tmp == WALL || tmp == BOX)){
                grid->game_grid[y][x-1] = PLAYER;
                grid->game_grid[y][x] = NONE;          
                grid->player.x = x-1;
            }
            break;
        }
        case RIGHT: {
            enum CaseType tmp = grid->game_grid[y][x+1];
            printf("%c\n", tmp);
            if (!(tmp == WALL || tmp == BOX)){
                grid->game_grid[y][x+1] = PLAYER;
                grid->game_grid[y][x] = NONE;
                grid->player.x = x+1;
            }
            break;
        }
    }    
    return grid;    
}

// int main(){


//     return 0;
// }