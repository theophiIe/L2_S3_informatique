#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mes_types.h"

int nombre_echange,	nombre_comparaison;

//FONCTION QUI REMPLIT UN TABLEAU DE N CASE//
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

//FONCTION QUI LIBERE LA PLACE DANS UN TABLEAU//
void sup_tabint(TABINT tab)
{
	free(tab.T);
}

//FONCTION QUI PERMET D'AFFICHER UN TABLEAU//
void aff_tabint (TABINT tab)
{
	for(int i=0; i<tab.N; i++)
	{
		printf("T[%d]= %d\n",i,tab.T[i]);
	}
	printf("\n");
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

TABINT gen_croissant_tabint(int N, int K)
{
	TABINT tab=gen_alea_tabint(N,K);
	tri_bulle_tabint(tab);
	return tab;
}


TABINT gen_decroissant_tabint(int N, int K)
{
	TABINT tab=gen_croissant_tabint(N,K);
	for(int i=0; i < tab.N/2; i++)
	{
		int temp=tab.T[i];
		tab.T[i]=tab.T[tab.N-i-1];
		tab.T[tab.N-i-1]=temp;
	}
	return tab;
}

int main()
{
	TABINT tab = gen_alea_tabint(10,1000);
	/**aff_tabint(tab);
	ech_tabint(tab,5);
	aff_tabint(tab);
	scan_ech_tabint(tab,10);
	aff_tabint(tab);*/
	
	nombre_echange=0;
	nombre_comparaison=0;
	
	tri_bulle_tabint(tab);
	aff_tabint(tab);
	printf("nombre d'échange: %d, nombre de comparaisons: %d \n\n", nombre_echange,nombre_comparaison);
	sup_tabint(tab);
	
	nombre_echange=0;
	nombre_comparaison=0;
	
	TABINT tab1=gen_croissant_tabint(10,100);
	aff_tabint(tab1);
	printf("nombre d'échange: %d, nombre de comparaisons: %d \n\n", nombre_echange,nombre_comparaison);

	nombre_echange=0;
	nombre_comparaison=0;
	
	TABINT tab2=gen_decroissant_tabint(10,100);
	aff_tabint(tab2);
	printf("nombre d'échange: %d, nombre de comparaisons: %d \n\n", nombre_echange,nombre_comparaison);

return 0;}
