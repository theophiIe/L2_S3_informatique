#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int longueur(char* chaine)
{
	for(int i=0;1;i++)
	{
		if(chaine[i]=='\0')
		return i;
	}

return 0;
}

int longueur_rec(char* chaine)
{
	if(chaine[0]=='\0')
	return 0;
	return 1+longueur_rec(chaine+1);
}

int difference(char* chaine1, char* chaine2)
{
for(int i=0;i<longueur(chaine1) && longueur(chaine2);i++)
{
	if(chaine1[i]<chaine2[i])return -1;
	if(chaine2[i]<chaine1[i])return 1;
	if(longueur(chaine1)==longueur(chaine2))return 0;
	if(longueur(chaine1)<longueur(chaine2))return -1;
}
return 0;

}


int main(int argc, char** argv)
{

for(int i=1;i<argc;i++)
{
	printf("la chaine numéro %d contient %d caractere\n",i,longueur(argv[i]));
	printf("la chaine numéro %d contient %d caractere\n",i,longueur_rec(argv[i]));
}

return 0;
}
