#pragma once
#include "install_dir/include/SDL2/SDL.h"
#include "grid.h"
typedef struct SDLContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} SDLContext;

extern SDLContext context;

/** @brief 
 * Initialise une variable global `context` de type SDLContext
 *
 * Si il y a erreur pendant l'intialisation:
 *  context.window = NULL
 *  ou 
 *  context.renderer = NULL
 *
 * Les deux cas sont à testé !
 * 
 */
void sdl_init();
/** @brief
 * nettoie la variable global context 
 */
void sdl_quit();


/**
 * @brief Affiche la grille avec SDL2
 * 
 * @param grid Adresse de la grille à afficher
 */
void display_sdl2(Grid grid);