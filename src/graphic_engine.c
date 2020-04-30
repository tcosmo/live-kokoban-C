#include "graphic_engine.h"

/* Position of tiles on tileset. */
const int NB_TILES = 6;
const int TILE_POS[6][2] = {{6,11},{6,9},{0,1},{3,1},{1,1},{5,6}};

GraphicEngine* graphic_engine_new(int screen_w,
                         int screen_h,
                         const char* window_name,
                         int nb_worlds,
                         World* worlds)
{
    GraphicEngine* graphic_engine = (GraphicEngine*) malloc(sizeof(GraphicEngine));
    graphic_engine->screen_w = screen_w;
    graphic_engine->screen_h = screen_h;
    graphic_engine->window_name = window_name;
    graphic_engine->nb_worlds = nb_worlds;
    graphic_engine->current_world = 0;
    graphic_engine->worlds = worlds;

    graphic_engine->is_running = 1;
    return graphic_engine;
}

void graphic_engine_die(GraphicEngine* graphic_engine)
{
    al_destroy_display(graphic_engine->display);
    al_destroy_bitmap(graphic_engine->tileset);
    al_destroy_event_queue(graphic_engine->event_queue);
    free(graphic_engine);
}

void graphic_engine_init(GraphicEngine* graphic_engine)
{
    assert(al_init());
    assert(al_init_image_addon());
    graphic_engine->display = al_create_display(graphic_engine->screen_w, 
                                                graphic_engine->screen_h);
    assert(graphic_engine->display);
    al_set_window_title( graphic_engine->display, graphic_engine->window_name);
    assert(al_install_keyboard());
    graphic_engine->event_queue = al_create_event_queue();
    assert(graphic_engine->event_queue);
    al_register_event_source(graphic_engine->event_queue,
        al_get_display_event_source(graphic_engine->display));
    al_register_event_source(graphic_engine->event_queue,
        al_get_keyboard_event_source());
    graphic_engine->tileset = al_load_bitmap(TILESET_PATH);
    assert(graphic_engine->tileset);
}

void draw_cell(GraphicEngine* graphic_engine, Cell cell, int line, int col)
{
    float y_in_set = TILE_POS[cell][0]*TILE_W;
    float x_in_set = TILE_POS[cell][1]*TILE_W;

    al_draw_bitmap_region(graphic_engine->tileset, 
                          x_in_set, y_in_set, 
                          TILE_W, TILE_H, 
                          TILE_W*col, TILE_H*line, 0);
}

void draw_map(GraphicEngine* graphic_engine, World* world)
{
    for( int line = 0 ; line < world->height ; line += 1 )
        for( int col = 0 ; col < world->width ; col += 1 ) {
            draw_cell(graphic_engine, EMPTY, line, col);

            Cell cell = world->cells[line][col];
            
            if( cell != PLAYER_ON_GOAL )
                draw_cell(graphic_engine, cell, line, col);
            else {
                draw_cell(graphic_engine, GOAL, line, col);
                draw_cell(graphic_engine, PLAYER, line, col);
            }
        }
}

void graphic_engine_run(GraphicEngine* graphic_engine)
{
    ALLEGRO_TRANSFORM t;
    al_identity_transform(&t);
    al_scale_transform(&t, 0.6, 0.6);
    al_use_transform(&t);

    int curr_world_id = graphic_engine->current_world;
    World* world = &graphic_engine->worlds[curr_world_id];

    while( graphic_engine->is_running ) {
        if( world_won(world) ) {
            if( curr_world_id+1 < graphic_engine->nb_worlds ) {
                curr_world_id += 1;
                world = &graphic_engine->worlds[curr_world_id];
            }
            else 
                graphic_engine->is_running = false;
        }

        al_clear_to_color(BLACK);
        draw_map(graphic_engine, world);
        al_flip_display();

        ALLEGRO_EVENT event;
        al_wait_for_event(graphic_engine->event_queue, &event);

        if(event.type == ALLEGRO_EVENT_KEY_DOWN) {

            switch(event.keyboard.keycode) {
            case ALLEGRO_KEY_UP:    move_player(world, 0, -1); break;
            case ALLEGRO_KEY_RIGHT: move_player(world, 1, 0);  break;
            case ALLEGRO_KEY_DOWN:  move_player(world, 0, 1);  break;
            case ALLEGRO_KEY_LEFT:  move_player(world, -1, 0);  break;
            case ALLEGRO_KEY_ESCAPE: graphic_engine->is_running = 0; break;
            }

        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            graphic_engine->is_running = 0;
    }
}