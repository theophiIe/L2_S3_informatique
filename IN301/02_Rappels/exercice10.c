#include <stdlib.h>
#include <stdio.h>

//NOMBRE PREMIER

int main()
{

int nbre, x=1;
scanf("%d",&nbre);

if(nbre==1)
{
	printf("%d n'est pas un nombre premier",nbre);
return 0;
}

for(int i=nbre-1; i!=1; i--)
{
	if(nbre%i==0)
	{
		x=0;
		break;
	}
}

if(x)
	printf("%d est un nombre premier",nbre);

else
	printf("%d n'est pas un nombre premier",nbre);

return 0;
}
