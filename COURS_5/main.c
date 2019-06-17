#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "chrono.h"
#include "file.h"

//remplit une pile avec n valeurs entre 1 et k
void test_pile(){
  int n = 10000;
  int k = 1000;
  Pile p = creer_pile();
  int i;

  start();

  //ajoute n valeurs dans la pile
  for(i=0; i<n; i++)
    p = push(p, 1+rand()%k);
  
  //vide la pile
  while(!est_vide(p))
    p = pop(p);

  printf("Test PILE executé en %.2f millisecondes.\n", stop());

}

void test_file(){
  int n = 10000;
  int k = 1000;
  File f = creer_file();
  int i;

  start();

  //ajoute n valeurs dans la pile
  for(i=0; i<n; i++)
    f = enfile(f, 1+rand()%k);
  
  //vide la pile
  while(!est_vide(f))
    f = defile(f);

  printf("Test FILE executé en %.2f millisecondes.\n", stop());

}

int main(){
  
  test_pile();
  test_file();
  
  exit(EXIT_SUCCESS);
}
