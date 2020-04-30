#ifndef DEF_GLOBAL_H
#define DEF_GLOBAL_H

#if defined(_WIN32) || defined(__MINGW32__) || defined(__CYGWIN__)
    #define WORLDS_FILE_PATH   "worlds\\default.txt"
    #define TILESET_PATH       "tiles\\tileset.bmp"
#else
    #define WORLDS_FILE_PATH   "worlds/default.txt"
    #define TILESET_PATH       "tiles/tileset.bmp"
#endif

#define MAX_BUFFER_SIZE 128
#define WHITE al_map_rgb(1,1,1)
#define BLACK al_map_rgb(0,0,0)


#define TILE_W 64
#define TILE_H 64 

extern const int NB_TILES;
extern const int TILE_POS[6][2];

#endif