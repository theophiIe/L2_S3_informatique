#include <stdio.h>
#include <stdlib.h>

//Programme qui affiche des étoiles

int main()
{
int a=10;

for(int i=0;i<10;i++)
{
	for(int j=1;j<a;j++)
	{
	printf("%c",32);
	}
	printf("\052\n");
	a--;
	}
return 0;
}
