#include "main.h"

int main(void){
	
	Grid grid = init_level("/adhome/lmocan/Documents/SokobanTechDev/level1.txt");
	affiche_niveau(grid);

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
					affiche_niveau(grid);
				}
				break;
			}
		}
	}
	return 0;
}

