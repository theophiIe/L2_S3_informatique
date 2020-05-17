#include <stdlib.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "afficher.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"



SUDOKU jouer(SUDOKU S) {
	int fleche; 
	char touche;
	POINT P;
	int res = wait_key_arrow_clic(&touche,&fleche,&P);
	
	if(EST_CLIC == res){
		if (P.y < HAUTEUR-TAILLE_CASE) {
			S.y = P.x/TAILLE_CASE; 	//Numéro de la case par rapport à la colonne
			S.x = P.y/TAILLE_CASE; 	//Numéro de la case par rapport à la ligne
			S.n++;                 	//Permet d'augmenter la position du tableau pour le Undo
			S = sudoku_modifier_case(S);
		return S;
		}
	}

	if(EST_TOUCHE == res){
		if('U' == touche){ //Undo
			S = undo(S, position_case_x(S), position_case_y(S));
			S.n--;
			printf("undo\n");
		}
		
		else if('V' == touche){
			//Corrige le sudoku
		}
		
		else if('S' == touche){ //Sauvegarde
			printf("sauvegarde faite\n");
			ecrire_fichier(S);
			S.save ++;
		}
			
		else if('Q' == touche){ //Quitte
			printf("Partie terminer\n");
			exit(0);
		}
	}
	
	return S;
}


int main (int argc, char *argv[]) {
	SUDOKU S;
	S = lire_fichier(argv[1]);
	initialiser_fenetre_graphique();
	sudoku_afficher(S,argv[1],victoire(S));
	
	while(1){
		S = jouer(S);
		sudoku_afficher(S,argv[1],victoire(S));
	}
	
	terminer_fenetre_graphique();
	exit(0);
}
