#ifndef PLAYER_HEADER
#define PLAYER_HEADER

enum Direction {
    TOP = 'w',
    LEFT = 'a',
    RIGHT = 'd',
    BOTTOM = 's'
};

typedef struct Player{
    float x;
    float y;
} Player;

#endif