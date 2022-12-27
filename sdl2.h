#pragma once
#include "install_dir/include/SDL2/SDL.h"
#include "grid.h"

/**
 * @enum Event
 * @brief Des actions que l'on peut effectuer dans le jeu.
 */
enum Event {
  Quit, 
  Left, 
  Right, 
  Up, 
  Down,
  None
};

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


/**
 * @brief renvoye le type d'action à effectuer.
 * 
 * @return enum Event 
 */
enum Event event_sdl2();


enum Direction event_to_direction(enum Event event);