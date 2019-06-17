#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"


Arbre creer_racine(char c){
  Arbre a;
  a = malloc(sizeof(Noeud));
  if(a == NULL ){
    fprintf(stderr, "Erreur allocation memoire pour arbre\n");
    exit(EXIT_FAILURE);
  }
  a->c = c;
  a->g = a->d = NULL ;
  return a;
}

//affiche l'arbre selon la profondeur
void affiche_arbre_prof(Arbre a, int p){
  int i;
  if(a != NULL ){
    for(i=0; i<p; i++)//decalage selon la profondeur
      printf("     ");
    printf("%c\n", a->c);
    affiche_arbre_prof(a->g, p+1);
    affiche_arbre_prof(a->d, p+1);

  }
}

int maximum(int a, int b){
  if(a>b) return a;
  else return b;
}

int hauteur(Arbre a){
  if(a == NULL )
    return 0;
  return 1 + maximum(hauteur(a->g), hauteur(a->d));
}


int est_feuille(Arbre a){
  return a != NULL  && a->g == NULL  && a->d == NULL ;
}

void affiche_arbre(Arbre a){
  affiche_arbre_prof(a, 0);
}



Arbre gauche(Arbre a){
  return a->g;
}

Arbre droite(Arbre a){
  return a->d;
}

char racine(Arbre a){
  return a->c;
}

Arbre chg_gauche(Arbre a, Arbre ag){
  if(a == NULL ){
    fprintf(stderr, "changement arbre gauche d'un arbre vide\n");
    exit(EXIT_FAILURE);
  }
  a->g = ag;
  return a;
}

Arbre chg_droite(Arbre a, Arbre ad){
  if(a == NULL ){
    fprintf(stderr, "changement arbre gauche d'un arbre vide\n");
    exit(EXIT_FAILURE);
  }
  a->d = ad;
  return a;
}

arbreF extraire_min(FP *F){
	int j;
	int min_pos=0;
	for(j=1; j<F->taille;j++){
		if(F->File[min_pos].Freq>F->File[j].Freq){
			min_pos=j;
			res=F->File[min_pos];
	}
	for(int i=min_pos+1; i<F->taille;i++){
		F->File[i-1]=F->File[i];
	}
	F->taille --;
	return res;
}

FP ajoute(FP *F, arbreF a){
	F.File[F.taille]=a;
	F.taille++;
	return F;
}

arbreF fusion(arbreF a,arbreF b){
	
	
}

FP init(int *Frequence){
	
	
}
