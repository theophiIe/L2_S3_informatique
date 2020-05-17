#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>


// #####
// 1. Génération, suppression et affichage de tableaux
// #####
TABINT gen_alea_tabint (int N, int K) {
	TABINT T;
	T.N = N;
	T.T = malloc(N*sizeof(int));
	if (T.T==NULL) exit(1);
	int i;
	for ( i=0 ; i<N ; i++) {
		T.T[i] = rand()%K;
	}
	return T;
}

TABINT sup_tabint (TABINT T) {
	free(T.T);
	T.N = 0;
	T.T = NULL;
	return T;
}

void aff_tabint (TABINT T) {
	printf("  N = %d : ",T.N);
	int i;
	for ( i=0 ; i<T.N ; i++) {
		printf(" %d",T.T[i]);
	}
	printf("\n");
}

// #####
// 2. Manipulation des valeurs du tableau
// #####

// Echange la case i et la case i+1 si la case i est > à la case i+1
int ech_tabint (TABINT T, int i) {
#ifdef DEBUG1
	if (i>=T.N-1) exit(3);
	if (i<0) exit(4);
#endif
	// Incrémentation de la stat
		NBCOMP++;
	if (T.T[i] <= T.T[i+1]) return 0;
	int tmp  = T.T[i];
	T.T[i]   = T.T[i+1];
	T.T[i+1] = tmp;
	// Incrémentation de la stat
		NBECH++;
#ifdef DEBUG2
	aff_tabint (T);
#endif
	return 1;
}
#define GAUCHE 12
#define DROITE 13
// fusionne les deux tableau triés [deb..mil] et [mil+1..fin]
void fusionner (TABINT T, int deb, int mil, int fin) {
	int N=fin-deb+1;
	int T2 [N];
	int ig,id,i;
	ig=deb;id=mil+1;i=0;
	while(i<N){
		if(ig<=mil) && (id<=fin) {if(T[ig]<T[id])petit =GAUCHE;else petit=DROITE;}
		if(ig>mil) petit=DROITE;
		if(id>fin) petit=GAUCHE;
		if (petit==GAUCHE){T2[i]=T.T[ig];ig++;}
		if (petit==DROITE){T2[i]=T.T[id];id++;}
}
}

int verif_si_tableau_croissant (TABINT T) {
	int i;
	for ( i=1 ; i<T.N ; i++)
		if (T.T[i]<T.T[i-1]) {
			fprintf(stderr,"TABLEAU NON TRIÉ\n");
			return 0;
		}
	fprintf(stderr,"TABLEAU TRIÉ\n");
	return 1;
}
