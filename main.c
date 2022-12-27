#include <stdio.h>
#include <stdbool.h>
#include "grid.h"
#include "sdl2.h"


int main(){
	// call function to initialize SDL2 window
	sdl_init();
	
	Grid grid = init_level("level2.txt");
	// display_level(grid);
	display_sdl2(grid);

	bool run = true;
	while(run){
	// 	char entry = fgetc(stdin);
	// 	switch(entry){
	// 		case 'q' :{
	// 			run = false;
	// 			break;
	// 		}
	// 		default: {
	// 			if (entry == 'a' || entry == 'w' || entry == 's' || entry == 'd'){
	// 				grid = move_player(grid, entry);
	// 				// display_level(grid);
	// 				display_sdl2(grid);
	// 			}
	// 			// printf("targets found: %d\n", grid->covered_targets);
	// 			if (checkIfDone(grid)){
	// 				run = false;
	// 				freeGrid(grid);
	// 			}
	// 			break;
	// 		}
	// 	}
	// }
		enum Event event = event_sdl2();
		switch(event){
			case Quit: {
				run = false;
				break;
			}
			default: {
				if (event != None){
						printf("%c", event);
						enum Direction entry = event_to_direction(event);
						if (entry != UNDEFINED){
							grid = move_player(grid, entry);
							display_sdl2(grid);
						}
				}
				if (checkIfDone(grid)){
					run = false;
					freeGrid(grid);
				}
			}
		}
	}
	// call function to close SDL2 window
	sdl_quit();
	return 0;
}

