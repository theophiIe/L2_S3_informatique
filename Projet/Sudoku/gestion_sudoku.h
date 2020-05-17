#include "constantes.h"

#ifndef __SUDOKU_H
#define __SUDOKU_H

//STRUCT SUDOKU
struct une_case {
	int val;			//Valeur d'une case
	int modifiable;		//Permet de savoir si c'est un case de départ ou une case jouable
};

struct sudoku {
	int save;			//Permet de changer le numéro de la sauvegarde 
	int x;				//Permet de savoir dans quelle ligne la case se situe 
	int y;				//Permet de savoir dans quelle colonne se situe la case 
	int n;				//Permet de savoir dans quelle case du tableau l'on se situe pour le undo 
	struct une_case la_case[N][N]; //les cases du Sudoku
};

typedef struct sudoku SUDOKU;

//APPEL DES FONCTIONS
SUDOKU initialiser_sudoku();
SUDOKU sudoku_modifier_case(SUDOKU);
int valeur_suivante(SUDOKU S, int x, int y);
int valeur_precedente(SUDOKU S, int x, int y);
int position_case_x(SUDOKU S);
int position_case_y(SUDOKU S);
SUDOKU undo(SUDOKU S,int x, int y); 
int victoire(SUDOKU S);
#endif
