#ifndef PLAYER_HEADER
#define PLAYER_HEADER

enum Direction {
    TOP = '↑',
    LEFT = '←',
    RIGHT = '→',
    BOTTOM = '↓'
}

typedef struct Player {
    float x;
    float y;
} Player;

#endif