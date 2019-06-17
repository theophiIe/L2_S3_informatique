#include "pile.h"

Pile creer_pile(){
  /**Pile p;
  p.som = 0;
  return p;
  */
  return NULL;
}

int est_vide(Pile p){
  /**return p.som == 0;
  */
  if(p==NULL)
	return 1;
  else
	return 0;
}

Pile push(Pile p, int v){
  /**if(p.som == NMAX){
    fprintf(stderr, "\nechec push: pile pleine\n");
    exit(EXIT_FAILURE);
  }
  p.t[p.som] = v;
  p.som++;
  return p;
  */
  return insere_deb(p, v); 
}

Pile pop(Pile p){
  /**if(est_vide(p)){
    fprintf(stderr,"\néchec suppression: pile vide\n");
    exit(EXIT_FAILURE);
  }
  p.som--;
  return p;
  */
  return supprime_deb(p);
}

int pick(Pile p){
  /**if(est_vide(p)){
    fprintf(stderr,"\néchec lecture: pile vide\n");
    exit(EXIT_FAILURE);
  }
  return p.t[p.som-1];
  */
  if(est_vide(p)){
	  exit(EXIT_FAILURE);
	 }
  return p->val;
}


void affiche_pile(Pile p){
  /**int i;
  for(i=0; i<p.som; i++)
    printf("%d ", p.t[i]);
  printf("\n##################################\n");
  */
  return affiche_liste(p);
}
