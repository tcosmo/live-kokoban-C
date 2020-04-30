#include "world.h"

void free_worlds(World* worlds)
{
    free(worlds);
}

int is_player(Cell c)
{
    return c == PLAYER || c == PLAYER_ON_GOAL;
}

void find_player(World* world, int* player_x, int* player_y)
{
    for( int line = 0 ; line < world->height ; line += 1 )
        for( int col = 0 ; col < world->width ; col += 1 ) {
            Cell c = world->cells[line][col];
            if( is_player(c) ) {
                *player_x = col;
                *player_y = line;
            }
        }
}

void move_player(World* world, int move_x, int move_y)
{
    int player_x, player_y;
    find_player(world, &player_x, &player_y);
    printf("%d %d\n", player_x, player_y);
}