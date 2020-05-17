#include <stdio.h>
#include <stdlib.h>

//Programme qui convertie des secondes en heures minutes et secondes

void affiche_heure_minute_seconde(int s)
{
int h,h1,s1,m,m1;

h=s/3600;	h1=s%3600;
m1=h1%60;	s1=m1%60;
	
if(h1>=60)
{
	m=h1/60;
		
	if(m1!=0)
	{
		printf("%d heures %d minute %d seconde",h,m,s1);
	}
	
	else
		printf("%d heures %d minute 0 seconde",h,m);
}
	
else if(m1!=0)
{
	printf("%d heures 0 minute %d seconde",h,s1);
}
else
	printf("%d heures 0 minute 0 seconde",h);
}

void affiche_minute_seconde(int s)
{
int m,m1,s1;
m=s/60;		m1=s%60;
s1=m1%60;
	
if(m1!=0)
{
	printf("0 heures %d minute %d seconde",m,s1);
}
	
else
	printf("0 heures %d minute 0 seconde",m);
}



int main()
{

int s;
printf("Nombres de secondes:");
scanf("%d",&s);

if(s>3600*24)
{
	printf("ERREUR");
}
	//N HEURES N MINUTES N SECONDES//
else if(s>=3600)
{
	affiche_heure_minute_seconde(s);
}
	//0 HEURES N MINUTES N SECONDES//
else if(s>=60)
{
	affiche_minute_seconde(s);
}
	//0 HEURE 0 MINUTE N SECONDE//
else 
	printf("%d secondes",s);
return 0;
}
