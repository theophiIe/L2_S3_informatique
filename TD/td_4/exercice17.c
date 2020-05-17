#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int test_double(char* chaine)
{
int i=0;
if(chaine[0]=='-')
	i++;
while((i<strlen(chaine)) && isdigit(chaine[i]))
{
	i++;
}

if(i==strlen(chaine)) 
return 1;

if(chaine[i]=='.')
{
while((i<strlen(chaine)) && (isdigit(chaine[i])))
{
	i++;
}

if(i==strlen(chaine)) 
	return 1;
}
return 0;
}

int main( int argc, char** argv){

  double somme=0;
int a=0;
  for(int i=0 ; i<argc ; i++)
{
    somme += atof(argv[i]);
	a=test_double(argv[i]);
	if(a==0)
	printf("la somme est de:%f \n",somme);
	else
	return 0;

}
	return 0;
}

