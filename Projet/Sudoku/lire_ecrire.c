#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_sudoku.h"

SUDOKU lire_fichier (char *nom) {
	SUDOKU S=initialiser_sudoku();
	S.save = 1;
	int x=0; 
	int y=8; //8 car on commence la lecture du fichier par en haut
	char caractere;
	FILE *f = fopen(nom, "r");
	
	while(y>=0) {
		while(x<9) {
			fscanf(f, "%c" , &caractere);
			switch(caractere){
				case '.' :
					S.la_case[y][x].val = 0;
					S.la_case[y][x].modifiable = 1;	//La case est MODIFABLE
					x=x+1;
					break ;
				
				case '\n':
					break;
				
				case '*':
					S.la_case[y][x].modifiable = 0;	//La case est NON MODIFIABLE
					break;

				default:
					S.la_case[y][x].val = atoi(&caractere); //atoi converti les char en int
					S.la_case[y][x].modifiable = (S.la_case[y][x].modifiable == 0) ? 0 : 1;
					x=x+1;
					break;
			}
		}
		y--;
		x=0;
	}
	fclose(f);
	return S;
}

//Permet de créer des sauvegardes
void ecrire_fichier(SUDOKU S) {
	//Permet de changer le nom de la sauvegarde
	char sauvegardes[] = "sauvegarde.000.sudoku";
	sauvegardes[13] = '0' + S.save % 10;
	sauvegardes[12] = '0' + (S.save / 10)% 10;
	sauvegardes[11] = '0' + (S.save /100) % 10;
	printf("%s\n",sauvegardes);
	
	FILE *f = fopen(sauvegardes, "w+"); //w+ pour effacer le contenu d'un fichier s'il est déjà existant pour pouvoir écrire par dessus
	for(int y=8; y>=0; y--){
		for(int x=0; x<=8; x++){
			switch(S.la_case[y][x].modifiable){
				
				case 0:		//La case est non modifiable
					fprintf(f,"*%d",S.la_case[y][x].val);
					break;
					
				case 1:		//La case est modifiable
					if(S.la_case[y][x].val == 0)
						fprintf(f,"%c", '.');
						
					if(S.la_case[y][x].val != 0)
						fprintf(f,"%d", S.la_case[y][x].val);
					break;
			}
			
		}
		fprintf(f,"%c", '\n');
	}
	fclose(f);
}


