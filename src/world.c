#include "world.h"

void free_worlds(World* worlds)
{
    free(worlds);
}

int is_player(Cell c)
{
    return c == PLAYER || c == PLAYER_ON_GOAL;
}

int is_crate(Cell c)
{
    return c == CRATE || c == CRATE_ON_GOAL;
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

int is_valid_position(World* world, int x, int y)
{
    return (x >= 0 && x < world->width ) && (y >= 0 && y < world->height);
}

void change_player_position(World* world, int old_x, int old_y, int new_x, int new_y)
{
    Cell* old_cell = &world->cells[old_y][old_x];
    if( *old_cell == PLAYER_ON_GOAL )
        *old_cell = GOAL;
    else
        *old_cell = EMPTY;

    Cell* new_cell = &world->cells[new_y][new_x];
    if( *new_cell == GOAL )
        *new_cell = PLAYER_ON_GOAL;
    else
        *new_cell = PLAYER;
}

void move_player(World* world, int move_x, int move_y)
{
    int player_x, player_y;
    find_player(world, &player_x, &player_y);
    
    int new_player_x = player_x + move_x;
    int new_player_y = player_y + move_y;

    if( !is_valid_position(world, new_player_x, new_player_y) )
        return;

    Cell next_cell = world->cells[new_player_y][new_player_x];

    if( next_cell == WALL || is_crate(next_cell) )
        return;

    change_player_position(world, player_x, player_y, new_player_x, new_player_y);
}