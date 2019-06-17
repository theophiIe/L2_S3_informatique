#include "tabint.h"
#include "stat.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fonction de balayage pour le tri à bulle
// fin doit être inférieur ou égal à T.N-1
int scan_ech_tabint (TABINT T, int fin) {
	int i;
	int echange = 0;
	for ( i=0 ; i<fin ; i++)
		 if (ech_tabint(T,i)) echange = 1;
	return echange;
}

void tri_bulle_tabint (TABINT T) {
	int fin = T.N-1;
	int echange = 1;
	while ( (fin>0) && (echange)){
//	while ( (fin>0) ){
		echange = scan_ech_tabint(T,fin);
		fin--;
	}
}

struct stat stat_moy (int N, int A) {
	int i;
	TABINT T;
	unsigned long long int TOTCOMP = 0;
	unsigned long long int TOTECH  = 0;
	for (i=0 ; i<A ; i++) {
		T = gen_alea_tabint(N,1000);
		NBCOMP = 0;
		NBECH  = 0;
		tri_bulle_tabint(T);
		TOTCOMP += NBCOMP;
		TOTECH  += NBECH;
#ifdef DEBUG1
printf("%3d: NBCOMP = %d, NBECH = %d\n",i,NBCOMP,NBECH);
#endif
		T = sup_tabint(T);
	}
	struct stat S;
	S.N = N;
	S.nb_moy_comp = (double)TOTCOMP/(double)A;
	S.nb_moy_ech  = (double)TOTECH /(double)A;
#ifdef DEBUG1
printf("N           = %d\n",S.N);
printf("nb_moy_comp = %.3lf\n",S.nb_moy_comp);
printf("nb_moy_ech  = %.3lf\n",S.nb_moy_ech);
#endif
	return S;
}

void ecrire_fichier_stat (struct stat S){
}

int main() {
#ifdef DEBUG1
printf("####\nDEBUT TRI A BULLE\n");
#endif
	struct stat S;
	S = stat_moy(100,20);
	ecrire_fichier_stat(S);

#ifdef DEBUG1
printf("FIN TRI A BULLE\n####\n");
#endif

	exit(0);
}

/*
int main() {
	TABINT T;
#ifdef DEBUG1
printf("####\nDEBUT TRI A BULLE\n");
#endif
	T = gen_alea_tabint (12, 1000);
	
	aff_tabint (T);
	tri_bulle_tabint(T);
	aff_tabint (T);

#ifdef DEBUG1
verif_si_tableau_croissant (T);
#endif
	T = sup_tabint(T);
#ifdef DEBUG1
printf("FIN TRI A BULLE\n####\n");
#endif

	exit(0);
}
*/
