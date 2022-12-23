#include <stdio.h>
#include <stdbool.h>
#include "grid.h"
#include "sdl2.h"


int main(void){
	// call function to initialize SDL2 window
	sdl_init();
	
	Grid grid = init_level("level1.txt");
	// display_level(grid);
	display_sdl2(grid);

	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'q' :{
				run = false;
				break;
			}
			default: {
				if (entry == 'a' || entry == 'w' || entry == 's' || entry == 'd'){
					grid = move_player(grid, entry);
					display_level(grid);
				}
				// printf("targets found: %d\n", grid->covered_targets);
				if (checkIfDone(grid)){
					run = false;
					freeGrid(grid);
				}
				break;
			}
		}
	}
	// call function to close SDL2 window
	sdl_quit();
	return 0;
}

