#include "main.h"

int main(void){
	
	Grid grid = init_level("level1.txt");
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
				printf("targets found: %d\n", grid->count_targets);
				if (checkIfDone(grid)){
					run = false;
					freeGrid(grid);
				}
				break;
			}
		}
	}
	return 0;
}

