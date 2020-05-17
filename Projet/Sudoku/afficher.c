#include <stdio.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"

//initialise la fenêtre graphique
void initialiser_fenetre_graphique() {
	init_graphics(LARGEUR,HAUTEUR);
	affiche_auto_off();
}

//affiche une case
void affiche_une_case(int x, int y) {
	POINT Bg, Hd;
	
	Bg.x = x*TAILLE_CASE;			Bg.y = y*TAILLE_CASE;
	Hd.x = Bg.x + TAILLE_CASE;		Hd.y = Bg.y + TAILLE_CASE;
	
	draw_rectangle(Bg,Hd,COUL_TRAIT);
}

//affiche trait de séparation
void traits_de_separation(int x, int y) {
	POINT Bg,Hd;
	
	Bg.x = x*TAILLE_GRANDE_CASE+1;		Bg.y = y*TAILLE_GRANDE_CASE+1;
	Hd.x = Bg.x + TAILLE_GRANDE_CASE;	Hd.y = Bg.y + TAILLE_GRANDE_CASE;
	
	draw_rectangle(Bg,Hd,COUL_TRAIT);
	
	Bg.x = x*TAILLE_GRANDE_CASE-1;		Bg.y = y*TAILLE_GRANDE_CASE-1;
	Hd.x = Bg.x + TAILLE_GRANDE_CASE; 	Hd.y = Bg.y + TAILLE_GRANDE_CASE;
	
	draw_rectangle(Bg,Hd,COUL_TRAIT);
}

void affiche_traits_de_separation() {
	for(int x=0 ; x<3 ; x++) 
		for(int y=0 ; y<3 ; y++) 
			traits_de_separation(x,y);
}

//affichage de la grille
void affiche_grille() {
	for(int x=0 ; x<N ; x++) 
		for(int y=0 ; y<N ; y++) 
			affiche_une_case(x,y);
}

//Affiche nombre
void nombre(SUDOKU S){
	POINT p;
		for(int x=0 ; x<N ; x++){ 
			for(int y=0 ; y<N ; y++){
				p.x=x*TAILLE_CASE+TAILLE_CASE/4;	p.y=y*TAILLE_CASE+TAILLE_CASE;

				if((S.la_case[y][x].val!=0) && (S.la_case[y][x].modifiable ==1))
					aff_int(S.la_case[y][x].val,TAILLE_POLICE,p,COUL_VAL_TRAVAIL); //Affiche les nombres d'une case modifiable
				
				else if((S.la_case[y][x].val!=0) && (S.la_case[y][x].modifiable ==0))
					aff_int(S.la_case[y][x].val,TAILLE_POLICE,p,COUL_VAL_DEPART); //Affiche les nombres d'une case de départ
			}
		}
}

//Permet d'afficher le nom du fichier ou gagné si le soduku est rempli
void nom_fichier_et_fin(char *nom, int n){
	POINT p;
	p.x=0;	p.y=HAUTEUR;

	if(n == 81){
		aff_pol("GAGNE",TAILLE_POLICE,p,COUL_TITRE);
		wait_escape();
		exit(0);
	}
	else aff_pol(nom,TAILLE_POLICE,p,COUL_TITRE);//Affiche le nom du fichié
}

void terminer_fenetre_graphique() {
	wait_escape();
}

//affiche toutes les fonctions permettant l'affichage
void sudoku_afficher(SUDOKU S,char *nom, int n) {
	fill_screen(COUL_FOND);
	affiche_grille();
	affiche_traits_de_separation();
	nombre(S);
	nom_fichier_et_fin(nom,n);
	affiche_all();
	
}
