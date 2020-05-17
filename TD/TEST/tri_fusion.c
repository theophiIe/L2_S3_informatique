#include "tabint.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fonction récursive des appels de tri_fusion sur le tableau [deb..fin]
void tri_fusion_rec (TABINT T, int deb, int fin) {
	#ifdef DEBUG1
	int i;
	for(i=0;i<level;i++){printf("  ");
	if(fin<deb)
	{
	printf("PB:fin<deb\n");
	exit(31);
	}
	#endif

//fin de la recursion
	if (fin==deb) return ;

//recursion
	int mil =(deb+fin)/2;
	tri_fusion_rec(T, deb ,mil);
	tri_fusion_rec(T,mil+1,fin);
	fusionner(T,deb,mil,fin);
}


void tri_fusion_tabint (TABINT T) {
	tri_fusion_rec(T,0,T.N-1);
}


int main() {
	TABINT T;
	
#ifdef DEBUG1
printf("####\nDEBUT TRI FUSION\n");
#endif

	T = gen_alea_tabint (12, 1000);
	
	aff_tabint (T);
	tri_fusion_tabint(T);
	aff_tabint (T);

#ifdef DEBUG1
verif_si_tableau_croissant (T);
#endif
	T = sup_tabint(T);
#ifdef DEBUG1
printf("FIN TRI FUSION\n####\n");
#endif

	exit(0);
}
