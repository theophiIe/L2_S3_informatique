#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mes_types.h"

int nombre_echange,nombre_comparaison;

TABINT gen_alea_tabint(int N, int K)
{
	TABINT tab;
	tab.T = malloc(N*sizeof(int));
	tab.N = N;
	srand(getpid());
	for(int i=0; i<tab.N; i++)
	{
		tab.T[i]=rand()%K;
	}
return tab;
}

void sup_tabint(TABINT tab)
{
	free(tab.T);
}


void ech_tabint(TABINT tab, int i)
{
	nombre_comparaison++;
	if(tab.T[i] > tab.T[i+1])
	{
		int temp = tab.T[i];
		tab.T[i] = tab.T[i+1];
		tab.T[i+1] = temp;
		
		nombre_echange++;
	}
}

void scan_ech_tabint (TABINT tab, int fin)
{
	for(int i=0; i < fin-1; i++)
	{
		ech_tabint(tab,i);
	}
}

void tri_bulle_tabint(TABINT tab)
{
	for(int i=tab.N; i>0; i--)
	{
		scan_ech_tabint(tab,i);
	}

}

void aff_tabint (TABINT tab)
{
	for(int i=0; i<tab.N; i++)
	{
		printf("T[%d]= %d\n",i,tab.T[i]);
	}
	printf("\n");
}

STAT stat_moy(int N, int A)
{

	srand(getpid());
	
	STAT compteur;
	TABINT tab;
	
	for(int i=0; i<A; i++)
	{
		tab=gen_alea_tabint(N, 500);
		tri_bulle_tabint(tab);
	}

	compteur.nb_moy_comp = nombre_comparaison/A;
	compteur.nb_moy_ech = nombre_echange/A;

return compteur;
}

int main()
{
	
	TABINT tab = gen_alea_tabint(10,1000);
	STAT compteur = stat_moy(10, 100);
	nombre_echange=0;
	nombre_comparaison=0;
	
	tri_bulle_tabint(tab);
	aff_tabint(tab);
	printf("nombre d'échange: %d, nombre de comparaisons: %d \n\n", nombre_echange,nombre_comparaison);
	printf("compteur: %d \n\n", compteur);

	sup_tabint(tab);

return 0;
}
