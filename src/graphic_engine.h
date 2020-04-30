#ifndef DEF_GRAPHIC_ENGINE_H
#define DEF_GRAPHIC_ENGINE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "global.h"
#include "world.h"

typedef struct 
{
    int screen_w, screen_h;
    const char* window_name;

    int is_running;

    int nb_worlds, current_world;
    World* worlds;

    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* event_queue;
    ALLEGRO_BITMAP* tileset; 
} GraphicEngine;

GraphicEngine* graphic_engine_new(int screen_w, int screen_h,
                                  const char* window_name,
                                  int nb_worlds,
                                  World* worlds);

void graphic_engine_init(GraphicEngine* graphic_engine);

void graphic_engine_run(GraphicEngine* graphic_engine);
void graphic_engine_die(GraphicEngine* graphic_engine);

#endif