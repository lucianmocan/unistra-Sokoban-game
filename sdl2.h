#pragma once
#include "install_dir/include/SDL2/SDL.h"
#include "grid.h"

/**
 * @struct SDLContext sdl2.h
 * @brief Cette structure contient des informations
 * concernant l'environnement SDL initialisé.
 */
typedef struct SDLContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} SDLContext;

extern SDLContext context;

void sdl_init();

void sdl_quit();

void display_sdl2(Grid grid);

enum Event event_sdl2();
