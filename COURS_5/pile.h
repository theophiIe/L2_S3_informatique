#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

#define NMAX 10000

/**struct pile{
  int t[NMAX];
  int som;
};
typedef struct pile Pile;
*/


typedef Liste Pile;

Pile creer_pile();//creer un pile vide

int est_vide(Pile p);//verifie si la pile est vide

Pile push(Pile p, int v);//implementer au debut de la liste 

Pile pop(Pile p);//retire le premier element de la liste 

int pick(Pile p);//revoie la premiere valeur sans le supprimer

void affiche_pile(Pile p);

