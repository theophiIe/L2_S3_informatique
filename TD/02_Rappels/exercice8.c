#include <stdio.h>
#include <stdlib.h>

//Progamme multiplication égyptienne

int main()
{
int X,Y,Z,R;

	scanf("%d", &X);
	scanf("%d", &Y);
	Z=0;
	
printf("%d*%d \n",X,Y);

while(X>1)
{
	if(X%2==1)
	{
		X=X-1;	Z=Y+Z;
		printf("=%d*%d+%d \n",X,Y,Z);
	}
	
	else if(X%2==0)
	{
		X=X/2;	Y=Y*2;
		printf("=%d*%d+%d \n",X,Y,Z);
	}
}

R=X*Y+Z;
printf("=%d \n",R);

return 0;
}
