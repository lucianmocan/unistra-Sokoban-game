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

typedef struct StrGoals{
    Goal* arrayOfGoals;
    int size;
} StrGoals;

typedef struct Point{
    int x;
    int y;
} Point;
#endif