#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
srand(getpid());

int i;

for(i=0;i<10000;i++)
{
	printf("%d\n",rand()%1000);
}
 return 0;
}
