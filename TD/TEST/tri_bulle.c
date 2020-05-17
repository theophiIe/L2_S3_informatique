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

struct stat calcul_stat(int N){
	TABINT T;

	int A = (int)1e4;
	int K=(int)1e2;

	int i;
	NBECH = 0;
	NBCOMP = 0;
	
	for(i=0;i<K;i++){
	T = gen_alea_tabint (N, A);
	//aff_tabint (T);
	tri_bulle_tabint(T);
	//printf("NBECH = %llu, NBCOMP = %llu\n",NBECH,NBCOMP);
	//aff_tabint (T);
}
struct stat S;
	S.N=N;
	S.nb_moy_ech =(double)NBECH /(double)K;
	S.nb_moy_comp = (double)NBCOMP/(double)K;

//	printf("nb_comp=%lf ,comp moy=%lf\n",S.nb_moy_ech,S.nb_moy_comp);



return S;
}

int main() {
//	TABINT T;
//#ifdef DEBUG1
//printf("####\nDEBUT TRI A BULLE\n");
//#endif
struct stat S;
int N;
FILE *F;
F=fopen("test_tri_bulle.data","w");
if (F==NULL) exit(21);
	for(N=10;N<=10000;N=N*2){

			S=calcul_stat(N);
			fprintf(F,"%d %lf %lf\n",N,S.nb_moy_ech,S.nb_moy_comp);
			printf("%d %lf %lf\n",N,S.nb_moy_ech,S.nb_moy_comp);


}
fclose(F);
	exit(0);
}


//#ifdef DEBUG1
//verif_si_tableau_croissant (T);
//#endif
//	T = sup_tabint(T);
//#ifdef DEBUG1
//printf("FIN TRI A BULLE\n####\n");
//#endif



