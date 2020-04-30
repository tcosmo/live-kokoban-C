#include "worlds_file.h"

Cell char_to_cell(char c)
{
    switch (c) {
    case ' ': return EMPTY;
    case '#': return WALL;
    case '$': return CRATE;
    case '.': return GOAL;
    case '*': return CRATE_ON_GOAL;
    case '@': return PLAYER;
    case '+': return PLAYER_ON_GOAL;
    default:
        printf("FATAL: character %c is not a valid SOKOBAN input \
(cf https://fr.wikipedia.org/wiki/Sokoban#Formats_des_fichiers).\n", c);
        exit(-1);
    }
}

World* load_worlds_from_file(const char* file_path, int* nb_worlds)
{
    FILE *worlds_file  = fopen(file_path, "r");
    if( worlds_file == NULL ) {
        printf("FATAL: can't open worlds file %s\n", file_path);
        exit(-1);
    }

    int curr_nb_worlds = 0;
    World* worlds = (World*) malloc(sizeof(World));

    char line[MAX_BUFFER_SIZE];
    int i_line = 0;
    int max_width = 0;
    while( fgets(line, sizeof line, worlds_file) != NULL ) {
        if( line[0] == '~' ) {
            assert(curr_nb_worlds >= 1);
            worlds[curr_nb_worlds-1].height = i_line;
            worlds[curr_nb_worlds-1].width = max_width;
            i_line = 0;
            continue;
        }

        if( i_line == 0 )
        {
            curr_nb_worlds += 1;
            worlds = (World*) realloc(worlds,curr_nb_worlds*sizeof(World));
            strtok(line, "\n");
            memcpy(worlds[curr_nb_worlds-1].name, line, sizeof(line));
            i_line += 1;
            continue;
        }

        for( int i_col = 0 ; i_col < MAX_BUFFER_SIZE ; i_col += 1 )
            worlds[curr_nb_worlds-1].cells[i_line-1][i_col] = EMPTY;

        int i_char = 0;
        while( i_char < MAX_BUFFER_SIZE 
               && line[i_char] != '\n' 
               && line[i_char] != '\0' ) {
            char c = line[i_char];
            worlds[curr_nb_worlds-1].cells[i_line-1][i_char] = char_to_cell(c);
            i_char += 1;
        }
        if( i_char > max_width )
            max_width = i_char;
        i_line += 1;
    }
    fclose(worlds_file);

    *nb_worlds = curr_nb_worlds;
    return worlds;
}