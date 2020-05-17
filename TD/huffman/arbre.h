#ifndef _ARBRE_H
#define _ARBRE_H

struct noeud{
	char c;
	struct noeud* g;
	struct noeud* d;
};
typedef struct noeud Noeud;
typedef Noeud* Arbre;

typedef struct{
	arbre huf;
	int Freq;
}arbreF;

typedef struct{
	arbreF File[128];
	int taille;
}FP;

Arbre creer_racine(char c);

void affiche_arbre(Arbre a);

int hauteur(Arbre a);

int est_feuille(Arbre a);

Arbre gauche(Arbre a);

Arbre droite(Arbre a);

char racine(Arbre a);

Arbre chg_gauche(Arbre a, Arbre ag);

Arbre chg_droite(Arbre a, Arbre ad);



#endif
