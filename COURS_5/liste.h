#ifndef _LISTE_H
#define _LISTE_H

struct element{
  int val;// Valeur stockée
  struct element *suiv; // Pointeur vers le suivant
};
typedef struct element* Liste;

/**struct liste_alt{
	struct element *deb;
	struct element *fin;
};
typedef struct liste_alt Liste_alt
*/
void affiche_liste (Liste l);

Liste insere_deb(Liste l, int val);

Liste supprime_deb(Liste l);

Liste supprime_fin(Liste l);

Liste insere_fin(Liste l, int val);

#endif  
  
