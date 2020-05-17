#include <stdio.h>
#include <stdlib.h>

void echange (int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

int main()
{
	int a,b;
	a=24; 	b=12;
	
	echange(&a,&b);
	printf("a est égale:%d \n est b égale:%d \n",a,b);

return 0;
}
