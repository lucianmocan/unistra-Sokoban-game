#include "grid.h"
#include "player.h"
#include <stdlib.h>
#include <stdio.h>

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

	for (int i = 0; i < number_row; i++){
		for (int j = 0; j < number_column; j++){
			grid->game_grid[i] = (enum CaseType*) malloc(number_column*sizeof(enum CaseType));
		}
	}

	int current_row = 0;
	int current_goal = 0;

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
			current_column += 1;
			buffer += 1;
		}
		current_row += 1;
	}

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

// int main(){
	
// 	Grid grid = init_level("/adhome/lmocan/Documents/SokobanTechDev/level1.txt");
// 	affiche_niveau(grid);
// 	return 0;
// }


