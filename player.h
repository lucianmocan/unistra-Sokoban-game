#ifndef PLAYER_HEADER
#define PLAYER_HEADER

enum Direction {
    TOP = 'w',
    LEFT = 'a',
    RIGHT = 'd',
    BOTTOM = 's'
};

typedef struct Player{
    int x;
    int y;
} Player;

#endif