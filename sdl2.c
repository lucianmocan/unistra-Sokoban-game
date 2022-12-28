#include "sdl2.h"
#include "grid.h"

#define min(a,b) (a>b) ? b : a

SDLContext context; 

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
void sdl_init() {
  int const width = 1280;
  int const height = 720;
  context = (SDLContext){NULL, NULL, .width = 0, .height = 0};
  if (SDL_Init(SDL_INIT_VIDEO)) {
    return;
  }

  SDL_Window *window =
      SDL_CreateWindow("Sokoban", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
  if (!window) {
    return;
  }
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  context = (SDLContext){
      .window = window, .renderer = renderer, .width = width, .height = height};
}

/** @brief
 * nettoie la variable global context 
 */
void sdl_quit() {
  SDL_DestroyWindow(context.window);
  SDL_DestroyRenderer(context.renderer);
  context.window = NULL;
  context.renderer = NULL;
  SDL_Quit();
}

/**
 * @brief Affiche la grille avec SDL2
 * 
 * @param grid Adresse de la grille à afficher
 */
void display_sdl2(Grid grid){

  int wallsCountHorizontal = (int) context.width / grid->column_number;
  int wallsCountVertical = (int) context.height / grid->row_number;
  int cellSize = min(wallsCountVertical, wallsCountHorizontal);

  SDL_Renderer *renderer = context.renderer;

  SDL_SetRenderDrawColor(renderer, 126, 126, 126, 255); // couleur grise
  SDL_RenderClear(renderer); // On dessine toute la fenêtre en gris
  for (int i = 0; i < grid->row_number; i++){
    for (int j = 0; j < grid ->column_number; j++){
      if (grid->game_grid[i][j] == WALL){
        SDL_Rect rect = {    .x = j*cellSize,
                  .y = i*cellSize,
                  .w = cellSize,
                  .h = cellSize
              };
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0.5); // on choisit la couleur rouge
        SDL_RenderFillRect(renderer, &rect); // On dessine le rectangle
      }
      if (grid->game_grid[i][j] == PLAYER){
        SDL_Rect rect = {    .x = j*cellSize,
                  .y = i*cellSize,
                  .w = cellSize,
                  .h = cellSize
              };
        SDL_SetRenderDrawColor(renderer, 255, 99, 71, 1); // on choisit la couleur rouge
        SDL_RenderFillRect(renderer, &rect); // On dessine le rectangle
      }
      if (grid->game_grid[i][j] == BOX){
        SDL_Rect rect = {    .x = j*cellSize,
                  .y = i*cellSize,
                  .w = cellSize,
                  .h = cellSize
              };
        SDL_SetRenderDrawColor(renderer, 227, 186, 143, 1); // on choisit la couleur rouge
        SDL_RenderFillRect(renderer, &rect); // On dessine le rectangle
      }
      if (grid->game_grid[i][j] == GOAL){
        SDL_Rect rect = {    .x = j*cellSize,
                  .y = i*cellSize,
                  .w = cellSize,
                  .h = cellSize
              };
        SDL_SetRenderDrawColor(renderer, 255, 240, 0, 1); // on choisit la couleur rouge
        SDL_RenderFillRect(renderer, &rect); // On dessine le rectangle
      }
    }
  }
  SDL_RenderPresent(renderer); // On affiche tout
}

/**
 * @brief renvoye le type d'action à effectuer avec SDL2
 * 
 * @return enum Event 
 */
enum Event event_sdl2(){

  SDL_Event ev;
  SDL_WaitEvent(&ev);
  switch(ev.type){
    case SDL_QUIT:
      return Quit;
    case SDL_KEYDOWN:
      switch(ev.key.keysym.sym){
        case SDLK_UP:
          return Up;
        case SDLK_DOWN:
          return Down;
        case SDLK_LEFT:
          return Left;
        case SDLK_RIGHT:
          return Right;
      }
      break;
  }
  return None;
} 
