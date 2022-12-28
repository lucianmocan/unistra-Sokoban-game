#include <stdio.h>
#include <stdbool.h>
#include "grid.h"
#include "sdl2.h"

int main(){
	
	// initialisation du niveau du jeu à partir d'un fichier.
	Grid grid = init_level("level2.txt");

	// initialisation des pointeurs de fonction
	enum Event (*handle_event)() = event;
	void (*handle_display)(Grid) = display_level;

	// gestion de l'initialisation du SDL2 le cas échéant.
	if (handle_display == display_sdl2){
		// call function to initialize SDL2 window
		sdl_init();
	}
	handle_display(grid);

	bool run = true;
	while(run){
		enum Event ev = handle_event();
		switch(ev){
			case Quit: {
				run = false;
				break;
			}
			default: {
				if (ev != None){
					grid = move_player(grid, ev);
					handle_display(grid);
				}
				if (checkIfDone(grid)){
					run = false;
					freeGrid(grid);
				}
			}
		}
	}

	// gestion de la mise à fin du SDL2 le cas échéant.
	if (handle_display == display_sdl2){
		// call function to close SDL2 window
		sdl_quit();
	}
	return 0;
}