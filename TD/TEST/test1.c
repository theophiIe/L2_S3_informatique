#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct tabint 
{
    int N;  // Taille du tableau
    int *T; // Pointeur vers le tableau
};

typedef struct tabint TABINT;

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

void affichage(TABINT tab)
{
	for(int i=0; i<tab.N; i++)
	{
		printf("T[%d]= %d\n",i,tab.T[i]);
	}
	printf("\n");
}

void supprime(TABINT tab)
{
	free(tab.T);
}

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
	TABINT tab=gen_alea_tabint(6,100);
	affichage(tab);
	tri_bulle_tabint(tab);
	affichage(tab);
	supprime(tab);
return 0;
}
