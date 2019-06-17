#include "pile.h"

Pile creer_pile(){
  Pile p;
  p.som = 0;
  return p;
}

int est_vide(Pile p){
  return p.som == 0;
}


Pile push(Pile p, int v){
  if(p.som == NMAX-1){
    fprintf(stderr, "echec push: pile pleine\n");
    exit(EXIT_FAILURE);
  }
  p.t[p.som] = v;
  p.som++;
  return p;
}


Pile pop(Pile p){
  if(est_vide(p)){
    fprintf(stderr,"\néchec suppression: pile vide\n");
    exit(EXIT_FAILURE);
  }
  p.som--;
  return p;
}

int pick(Pile p){
  if(est_vide(p)){
    fprintf(stderr,"\néchec lecture: pile vide\n");
    exit(EXIT_FAILURE);
  }
  return p.t[p.som-1];
}
