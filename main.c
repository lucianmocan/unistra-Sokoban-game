#include <stdio.h>
#include <stdbool.h>
#include "grid.h"
#include "sdl2.h"

enum Event event();

int main(){
	// call function to initialize SDL2 window
	
	
	
	Grid grid = init_level("level2.txt");

	enum Event (*handle_event)() = event_sdl2;
	void (*handle_display)(Grid) = display_sdl2;
	if (handle_display == display_sdl2){
		sdl_init();
	}
	handle_display(grid);
	// display_level(grid);
	// display_sdl2(grid);

	bool run = true;
	while(run){
		enum Event ev = handle_event();
		// enum Event ev = event_sdl2();
		//    enum Event ev = event();
		switch(ev){
			case Quit: {
				run = false;
				break;
			}
			default: {
				if (ev != None){
					grid = move_player(grid, ev);
					handle_display(grid);
					// display_sdl2(grid);
					// display_level(grid);
				}
				if (checkIfDone(grid)){
					run = false;
					freeGrid(grid);
				}
			}
		}
	}

	if (handle_display == display_sdl2){
		// call function to close SDL2 window
		sdl_quit();
	}
	return 0;
}

enum Event event(){
	char entry = fgetc(stdin);
	switch(entry){
		case 'q':
			return Quit;
		case 'w':
			return Up;
		case 's':
			return Down;
		case 'a':
			return Left;
		case 'd':
			return Right;
		default:
			return None;
	}
}