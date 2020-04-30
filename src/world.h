/* Responsible for managing the state of the world. */

#ifndef DEF_WORLD_H
#define DEF_WORLD_H

#include <stdio.h>
#include <stdlib.h>

#include "global.h"

typedef enum 
{
    EMPTY = 0,
    WALL,          // #
    CRATE,         // $
    GOAL,          // .
    CRATE_ON_GOAL, // *
    PLAYER,        // @
    PLAYER_ON_GOAL // +
} Cell;


typedef struct
{
    char name[MAX_BUFFER_SIZE];
    int width, height;
    Cell cells[MAX_BUFFER_SIZE][MAX_BUFFER_SIZE];
} World;

void free_worlds(World* worlds);
void move_player(World* world, int move_x, int move_y);
int world_won(World* world);

#endif