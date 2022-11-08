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

typedef struct Goal{
    int x;
    int y;
} Goal;

typedef struct Goals{
    Goal* goals;
    int size;
} Goals;

#endif