#include "gestion_sudoku.h"

#ifndef __AFFICHER_H
#define __AFFICHER_H
// Fonction à appeler au début poour créer la fenêtre grapĥique
void initialiser_fenetre_graphique();

// Fonction à appeler à la fin pour terminer proprement la fenêtre grapĥique
void terminer_fenetre_graphique();

// Fonction qui affiche l'état courant du sudoku
void sudoku_afficher(SUDOKU S,char *nom, int n);

#endif
