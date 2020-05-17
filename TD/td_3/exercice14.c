#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void remplir(int* T)
{
	srand(getpid());
	
	for(int i=0; i<10; i++)
	{
		T[i]=rand()%20;
	}
}

void affiche(int* T)
{
	for(int i=0; i<10; i++)
	{
		printf("%d\n",T[i]);
	}
}

int retourne_produit(int* T)
{
	int prod=1;
	
	for(int i=0; i<10; i++)
	{
		prod*=T[i];
	}	
	
return prod;
}

int minimal(int* T)
{
	int minimum=T[0];
	
	for(int i=1; i<10; i++)
	{
		if(T[i]<minimum)
		{
			minimum=T[i];
		}
}
return minimum;
}

void decalage(int* T)
{
	
	for(int i=9; i>0; i--)
	{
		T[i]=T[i-1];
	}

affiche(T);
}

int* tableau()
{
	int* T;
	T=malloc(10*sizeof(int));
	srand(getpid());
	T[0]=rand()%10;
	
	for(int i=1; i<10; i++)
	{
		T[i]=T[i-1]+rand()%10;
	}

return T;
}

void insertion_triee(int* T, int valeur)
{
	for(int i=0; i<10 && T[i]<valeur;i++)
	{
		for(int j=10; j>i; j--)
		{
			T[j]=T[j-1];
		}

T[i]=valeur;
}
}

int main()
{
	int* T,a,b;
	T=malloc(10*sizeof(int));
	
	remplir(T);
	affiche(T);
	
	a=retourne_produit(T);
	printf("Le produit de tout les nombres du tableau est:%d\n",a);
	
	b=minimal(T);
	printf("La valeur minimal du tableau est:%d\n\n",b);
	
	decalage(T);
	
	T=tableau();
	printf("\n\n");
	affiche(T);

	insertion_triee(T,5);
	affiche(T);
	
return 0;
}		
		
		
		
		
		
		
