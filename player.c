
#include "grid.h"
#include "player.h"


bool search_point(Grid grid, Point p){
    printf("Current position: %d %d\n", p.x, p.y);
    for (int i = 0; i<grid->targets; i++){
        if (grid->goals.goals[i].x == p.x && grid->goals.goals[i].y == p.y){
            printf("Goal at this same position: %d %d\n", grid->goals.goals[i].x, grid->goals.goals[i].y);
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
    if (search_point(grid, (Point) {grid->player.x, grid->player.y})){
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
    enum CaseType t1 = grid->game_grid[c_1.y][c_1.x]; // valeur de la case c_1
    enum CaseType t2 = grid->game_grid[c_2.y][c_2.x]; // valeur de la case c_2
    enum CaseType* pt1 = &grid->game_grid[c_1.y][c_1.x]; // adresse de la case c_1
    enum CaseType* pt2 = &grid->game_grid[c_2.y][c_2.x]; // adresse de la case c_2
    if (t1 == BOX){
        if (t2 != WALL && !search_point(grid, c_1)){
            *pt1 = PLAYER;
            *pt2 = BOX;
            updatePreviousCell(grid);
            updatePlayerPosition(grid, c_1, motn_plane);
            if(t2 == GOAL){
                grid->count_targets++;
            }
        }
    }
    else {
        if (!(t1 == WALL)){
            *pt1 = PLAYER;
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