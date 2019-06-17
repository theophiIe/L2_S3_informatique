#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

struct Pile{
  int t[NMAX];
  int som;
};
typedef struct Pile Pile;


Pile creer_pile();

int est_vide(Pile p);

Pile push(Pile p, int v);

Pile pop(Pile p);

int pick(Pile p);
