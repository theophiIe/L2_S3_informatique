#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void affiche_liste (Liste l){
  if(l == NULL)
    printf("\n#############################\n");
  else{
    printf("%d ", l->val);
    affiche_liste(l->suiv);   
  }
}

Liste insere_deb(Liste l, int val){
  Liste lres;
  lres = malloc(sizeof(struct element));
  if(lres == NULL){
    fprintf(stderr, "ERREUR: échec malloc\n");
    exit(EXIT_FAILURE);
  }
  lres->val = val;
  lres->suiv = l;
  return lres;
}

Liste supprime_deb(Liste l){
  Liste ltmp;
  if(l == NULL){
    fprintf(stderr, "ERREUR: suppression dans liste vide\n");
    exit(EXIT_FAILURE);
  }
  ltmp = l->suiv;
  free(l);
  return ltmp;
}

Liste supprime_fin(Liste l){
  if(l == NULL){
    fprintf(stderr, "ERREUR: suppression dans liste vide\n");
    exit(EXIT_FAILURE);
  }
  if(l->suiv == NULL)//un seul elt
    return supprime_deb(l);
  l->suiv = supprime_fin(l->suiv);
  return l;
}

Liste insere_fin(Liste l, int val){
  if(l == NULL)
    return insere_deb(l, val);
  l->suiv = insere_fin(l->suiv, val);
  return l;
}


