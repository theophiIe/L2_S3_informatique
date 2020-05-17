#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "fdp.h"


int *Frequence(char* nom_fic){
	int* Freq=calloc(128 ,sizeof(int));
	FILE *f = fopen(nom_fic, "r");
	int c;
	c=fgetc(f);
	while(c != EOF){
		Freq[c]++;
		c=fgetc(f);
	}
	for(int i=0; i<128 ;i++){
		if(Freq[i]){
			printf("%c:%d \n",i,Freq[i]);
		}
	}
	fclose(f);
	return Freq;
}

//construit l'arbre d'huffman a partir du fichier ASCII nom_fic
Arbre arbre_huffman(char* nom_fic){


	return NULL ; 
}




int main(int argc, char** argv){
	Arbre a;

	if(argc != 2){
		fprintf(stderr, "Erreur: format de la ligne de commande attendu\n./main nom_du_fichier\n");
	exit(EXIT_FAILURE);
	}
	
	Frequence(argv[1]);

	a = arbre_huffman(argv[1]);
	affiche_arbre(a);

	exit(EXIT_SUCCESS);
}
