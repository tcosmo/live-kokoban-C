
#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "world.h"
#include "worlds_file.h"
#include "graphic_engine.h"

int main (int argc, char *argv[])
{
    int nb_worlds;
    World* worlds = load_worlds_from_file(WORLDS_FILE_PATH, &nb_worlds);
    GraphicEngine* graphic_engine = graphic_engine_new(1000, 800, "kokoban!!", 
                                                       nb_worlds, worlds);
    graphic_engine_init(graphic_engine);
    graphic_engine_run(graphic_engine);
    graphic_engine_die(graphic_engine);

    free_worlds(worlds);

    return 0;
}