#include "grid.h"

Grid init_level(const char* file_path){
	// ouverture du fichier en mode lecture
	FILE* file = fopen(file_path, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}

	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0; /// nombre de ligne
	int number_goals = 0;

	// on lit la première ligne du fichier
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
	
	Grid grid = (Grid) malloc(sizeof(str_grid));
	grid->column_number = number_column;
	grid->row_number = number_row;
	grid->game_grid = (enum CaseType**) malloc(number_row * sizeof(enum CaseType*));
	grid->targets = 0;
	grid->covered_targets = 0;
	grid->goals.size = number_column;
	grid->goals.count = 0;
	grid->goals.arrayOfGoals = (Goal*) malloc(10 * sizeof(Goal));

	for (int i = 0; i < number_row; i++){
		for (int j = 0; j < number_column; j++){
			grid->game_grid[i] = (enum CaseType*) malloc(number_column*sizeof(enum CaseType));
		}
	}

	int current_row = 0;
	// int current_goal = 0;

	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;
		while(*buffer && *buffer != '\n'){
			grid->game_grid[current_row][current_column] = *buffer;
			if (*buffer == PLAYER){
				grid->player.x = current_column;
				grid->player.y = current_row;
			}
			if (*buffer == GOAL){
				if (grid->goals.count == grid->goals.size){
					grid->goals.size += 10;
					grid->goals.arrayOfGoals = (Goal*) realloc(grid->goals.arrayOfGoals, grid->goals.size * sizeof(Goal));
				}
				grid->goals.arrayOfGoals[grid->targets].x = current_column;
				grid->goals.arrayOfGoals[grid->targets].y = current_row;
				grid->targets++;
			}
			current_column += 1;
			buffer += 1;
		}
		current_row += 1;
	}
	// for (int i = 0; i < grid->targets; i++){
	// 	printf("%d %d\n", grid->goals.goals[i].x, grid->goals.goals[i].y);
	// }
	printf("targets to find: %d\n", grid->targets);
	// fermeture du fichier
	fclose(file);
	return grid;
}

void affiche_niveau(Grid grid){
	
	for (int i = 0; i < grid->row_number; i++){
		for (int j = 0; j < grid->column_number; j++){
			printf("%c", grid->game_grid[i][j]);
		}
		putchar('\n');
	}
}

bool checkIfDone(Grid grid){
	return (grid->targets == grid->covered_targets);
}

void freeGrid(Grid grid){
	free(grid->goals.arrayOfGoals);
	free(grid->game_grid);
	free(grid);
}
// int main(){
	
// 	Grid grid = init_level("/adhome/lmocan/Documents/SokobanTechDev/level1.txt");
// 	affiche_niveau(grid);
// 	printf("Player position: %lf %lf\n", grid->player.x, grid->player.y);
// 	return 0;
// }


