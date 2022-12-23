#include "sdl2.h"
#include "grid.h"


SDLContext context; 

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

void sdl_quit() {
  SDL_DestroyWindow(context.window);
  SDL_DestroyRenderer(context.renderer);
  context.window = NULL;
  context.renderer = NULL;
  SDL_Quit();
}

void display_sdl2(Grid grid){
  printf("%d %d\n", context.height, context.width);
  SDL_Window *window = context.window;
  SDL_Renderer *renderer = context.renderer;

  SDL_SetRenderDrawColor(renderer, 126, 126, 126, 255); // couleur grise
  SDL_RenderClear(renderer); // On dessine toute la fenêtre en gris
  SDL_Rect rect = {    .x = 0,
                  .y = 0,
                  .w = 50,
                  .h = 50
              };
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // on choisit la couleur rouge
  SDL_RenderFillRect(renderer, &rect); // On dessine le rectangle
  SDL_RenderPresent(renderer); // On affiche tout
}