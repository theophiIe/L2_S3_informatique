#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ecrire()
{
	FILE*f=fopen(NOMFIC,"w");
	srand(getpid());
	
	for(int i=0; i<N; i++)
	{
		fprintf(f,"%6d\n",rand()%MAX);
	}
	fclose(f);
}

int main()
{
ecrire();
return 0;
}
