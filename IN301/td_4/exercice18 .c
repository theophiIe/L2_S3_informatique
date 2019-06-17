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

int main(int argc, char** argv)
{

for(int i=1;i<argc;i++)
{
	printf("la chaine numéro %d contient %d caractere",i,longueur(argv[i]));
}

return 0;
}
