
#include "grid.h"
#include "player.h"

Grid move_player(Grid grid, enum Direction direction){

    int x = grid->player.x;
    int y = grid->player.y;

    switch(direction){
        case TOP: {
            enum CaseType tmp_1 = grid->game_grid[y-1][x];
            enum CaseType tmp_2 = grid->game_grid[y-2][x];
            printf("%c\n", tmp_1);
            if (!(tmp_1 == WALL)){
                if (tmp_1 == BOX){
                    if(tmp_2 != WALL){
                        grid->game_grid[y-2][x] = BOX;
                    }
                }
                if (!(tmp_2 == WALL && tmp_1 == BOX)){
                    grid->game_grid[y-1][x] = PLAYER;
                    grid->game_grid[y][x] = NONE;
                    grid->player.y = y-1;
                }
            }
            break;
        }
        case BOTTOM: {
            enum CaseType tmp_1 = grid->game_grid[y+1][x];
            enum CaseType tmp_2 = grid->game_grid[y+2][x];
            printf("%c\n", tmp_1);
            if (!(tmp_1 == WALL)){
                if (tmp_1 == BOX){
                    if(tmp_2 != WALL){
                        grid->game_grid[y+2][x] = BOX;
                    }
                }
                if (!(tmp_2 == WALL && tmp_1 == BOX)){
                    grid->game_grid[y+1][x] = PLAYER;
                    grid->game_grid[y][x] = NONE;
                    grid->player.y = y+1;
                }
            }
            break;
        }
        case LEFT: {
            enum CaseType tmp_1 = grid->game_grid[y][x-1];
            enum CaseType tmp_2 = grid->game_grid[y][x-2];
            printf("%c\n", tmp_1);
            if (!(tmp_1 == WALL)){
                if (tmp_1 == BOX){
                    if(tmp_2 != WALL){
                        grid->game_grid[y][x-2] = BOX;
                    }
                }
                if (!(tmp_2 == WALL && tmp_1 == BOX)){
                    grid->game_grid[y][x-1] = PLAYER;
                    grid->game_grid[y][x] = NONE;
                    grid->player.x = x-1;
                }
            }
            break;
        }
        case RIGHT: {
            enum CaseType tmp_1 = grid->game_grid[y][x+1];
            enum CaseType tmp_2 = grid->game_grid[y][x+2];
            printf("%c\n", tmp_1);
            if (!(tmp_1 == WALL)){
                if (tmp_1 == BOX){
                    if(tmp_2 != WALL){
                        grid->game_grid[y][x+2] = BOX;
                    }
                }
                if (!(tmp_2 == WALL && tmp_1 == BOX)){
                    grid->game_grid[y][x+1] = PLAYER;
                    grid->game_grid[y][x] = NONE;
                    grid->player.x = x+1;
                }
            }
            break;
        }
    }    
    return grid;    
}


// int main(){


//     return 0;
// }