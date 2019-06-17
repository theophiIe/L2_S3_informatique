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



int main() {
	TABINT T;
#ifdef DEBUG1
printf("####\nDEBUT TRI A BULLE\n");
#endif
	int N = 12;
	int A = 1000;
	T = gen_alea_tabint (N, A);
	
	aff_tabint (T);
	NBECH = 0;
	NBCOMP = 0;
	tri_bulle_tabint(T);
	printf("NBECH = %llu, NBCOMP = %llu\n",NBECH,NBCOMP);
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

