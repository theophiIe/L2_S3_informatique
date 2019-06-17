#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int T[N];

int recherche(int x)
{
	for(int i=0; i<N || T[i]==x; i++)
	{
		return (i!=N);
	}
		return 0;
}

void lecture()
{
	FILE*f=fopen(NOMFIC,"r");
	
	for(int i=0; i<N; i++)
	{
		fscanf(f,"%d",&T[i]);
	}
		fclose(f);
		
		int i=0;
		while(fscanf(f,"%d",&T[i++])!=EOF){}
}

int main()
{
lecture();
return 0;
}

