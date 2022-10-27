#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <stdio.h>
#include <stdlib.h>

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