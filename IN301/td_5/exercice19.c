#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mes_types.h"

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

//FONCTION QUI PERMET DE D'ECHANGER LE CONTENUE D'UNE CASE I SI LA CASE EST SUPERIEUR//
void ech_tabint(TABINT tab, int i)
{
	if(tab.T[i] > tab.T[i+1])
	{
		int temp = tab.T[i];
		tab.T[i] = tab.T[i+1];
		tab.T[i+1] = temp;
	}
}

//FONCTION QUI PARCOURE TOUT LE TABLEAU ET ECHANGE LES VALUER EN FONTION DE SI ELLES SONT PLUS GRANDES 
void scan_ech_tabint (TABINT tab, int fin)
{
	for(int i=0; i < fin-1; i++)
	{
		ech_tabint(tab,i);
	}
}

//EFFECTUE UN TRI EN UTILISANT LA FONCTION SCAN ECHANGE TANT QUE LE TABLEAU N'EST PAS TOTALEMENT TRIE
void tri_bulle_tabint(TABINT tab)
{
	for(int i=tab.N; i>0; i--)
	{
		scan_ech_tabint(tab,i);
	}
}

int main()
{
	printf("géneration du tableau\n");
	TABINT tab = gen_alea_tabint(10,1000);
	aff_tabint(tab);
	
	printf("echange de la case[5] avec la case[6] du tableau\n");
	ech_tabint(tab,5);
	aff_tabint(tab);
	
	printf("echange les valeurs en parcourant le tableau une fois\n");
	scan_ech_tabint(tab,10);
	aff_tabint(tab);
	
	printf("tri le tableau du plus petit au plus grand\n");
	tri_bulle_tabint(tab);
	aff_tabint(tab);
	sup_tabint(tab);
	printf("\n");
return 0;
}
