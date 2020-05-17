#include <stdio.h>
#include <stdlib.h>
#include "gestion_sudoku.h"
#include "lire_ecrire.h"

//Initialise le sudoku
SUDOKU initialiser_sudoku (){
	SUDOKU S;
	int x,y;
	for (x=0 ; x<N ; x++)
		for (y=0 ; y<N ; y++) {
			S.la_case[x][y].modifiable = 1;		//Initialise toute les cases en tant que case modifiable
			S.la_case[x][y].val = 0; 			//Initialise toute les valeurs du Sudoku à 0
			S.n=0;								//Initialise le tableau stockant la position de la ligne et de la colonne de la case cliqué à 0 pour le Undo
		}
	return S;
}

//Permet d'augmenter la valeur d'une case 
int valeur_suivante(SUDOKU S, int x, int y){
	
	return (S.la_case[x][y].val + 1)%10;
}

//Permet d'avoir la valeur precedente de la case pour le Undo
int valeur_precedente(SUDOKU S, int x, int y){
	if(((S.la_case[x][y].val - 1)%10) < 0)	return 0;
	return (S.la_case[x][y].val - 1)%10;
}

//Vérifie si la valeur de la case utilisée est différente avec les autres valeurs de la colonne  
int colonne(SUDOKU S, int n, int y){
	for(int x=0;x<N;x++){
		if(n == S.la_case[x][y].val){
			return 1;
		}
	}
	return 0;
}

//Vérifie si la valeur de la case utilisée est différente avec les autres valeurs de la ligne
int ligne(SUDOKU S, int n ,int x){
	for(int y=0;y<N;y++){
		if(n == S.la_case[x][y].val){
			return 1;
		}
	}
	return 0;
}

//Vérifie si la valeur de la case utilisée est différente avec les autres valeurs de la zone
int zone(SUDOKU S, int n){
	int i,j,k,l;
	i = (S.x/3) * 3;
	j = (S.y/3) * 3 -1;
	k = i  +3;
	l = j + 3;
	
	while(l > j){
		i = (S.x/3)*3;
		while(i < k){
			if((n) == S.la_case[i][l].val){
				return 1 ;
			}
			i++;
		}
		l--;
	}
	return 0;
}

//Modifie la case cliqué dans le Sudoku
SUDOKU sudoku_modifier_case(SUDOKU S){ 
	if(S.la_case[S.x][S.y].modifiable == 1){
		if((ligne(S,S.la_case[S.x][S.y].val +1,S.x) == 0) && (colonne(S,S.la_case[S.x][S.y].val +1,S.y) == 0) && (zone(S,S.la_case[S.x][S.y].val +1) == 0)){
			S.la_case[S.x][S.y].val = valeur_suivante(S,S.x,S.y); 
			return S;
		}
		else{
			while((zone(S,S.la_case[S.x][S.y].val +1) == 1)  || (colonne(S,S.la_case[S.x][S.y].val +1,S.y)==1) || ligne(S,S.la_case[S.x][S.y].val +1,S.x)==1 ){
				S.la_case[S.x][S.y].val = valeur_suivante(S,S.x,S.y);
			}
			S.la_case[S.x][S.y].val = valeur_suivante(S,S.x,S.y);
		}
	}
	return S;
}

//Position de la ligne de la case pour le Undo
int position_case_x(SUDOKU S){
	int num_case_x[S.n];
	num_case_x[S.n]= S.x;
	return num_case_x[S.n];
}

//Position de la colonne de la case pour le Undo
int position_case_y(SUDOKU S){
	int num_case_y[S.n]; 
	num_case_y[S.n]= S.y;
	return num_case_y[S.n];
}

//Undo
SUDOKU undo(SUDOKU S,int x, int y){ 
	if(S.la_case[x][y].modifiable == 1){
		if((ligne(S,S.la_case[x][y].val - 1, position_case_x(S)) == 0) && (colonne(S,S.la_case[x][y].val - 1,position_case_y(S)) == 0) && (zone(S,S.la_case[x][y].val - 1) == 0)){
			S.la_case[x][y].val = valeur_precedente(S,x,y);
			return S;
		}
		else{
			while((zone(S,S.la_case[x][y].val - 1) == 1)  || (colonne(S,S.la_case[x][y].val - 1,position_case_y(S)) == 1) || ligne(S,S.la_case[x][y].val - 1,position_case_x(S)) == 1 ){
				S.la_case[x][y].val = valeur_precedente(S,x,y);
			}
			S.la_case[x][y].val = valeur_precedente(S,x,y);
		}
	}
	return S;
}

//Permet de savoir si toute les cases du Sudoku sont remplies
int victoire(SUDOKU S){
	int n=0;
	for (int x=0 ; x<N ; x++){
		for (int y=0 ; y<N ; y++) {
			if(S.la_case[x][y].val != 0){
				n++;
			}
		}
	}
	return n;
}
