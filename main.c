#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "grid.h"
#include "sdl2.h"

int main(int argc, char *argv[]){

	enum Event (*handle_event)();
	void (*handle_display)(Grid);
	
	if (argc == 1 || strcmp(argv[1],"--console") == 0){
		// initialisation des pointeurs de fonction
		handle_event = event;
		handle_display = display_level;
	}
	else if (strcmp(argv[1], "--sdl2") == 0){
		// initialisation des pointeurs de fonction
		handle_event = event_sdl2;
		handle_display = display_sdl2;
	}
	
	// initialisation du niveau du jeu à partir d'un fichier.
	Grid grid = init_level("level2.txt");

	// gestion de l'initialisation du SDL2 le cas échéant.
	if (handle_display == display_sdl2){
		// call function to initialize SDL2 window
		sdl_init();
		if (context.window == NULL || context.renderer == NULL){
			printf("Error! Cannot initialize SDL2! Program will quit now.\n");
			exit(1);
		}
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