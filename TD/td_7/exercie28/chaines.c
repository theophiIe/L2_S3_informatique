#include <stdio.h>
#include <stdlib.h>

int parenthese2(char *s)
{
	int pos = 1;
	int indice = 0;
	int parenth_ouvert = 1;
	int parenth_ferme = 0;
	
	while(s[pos] != '\0')
	{
		if(s[pos] == '(')	{parenth_ouvert++;}
		
		if(s[pos] == ')')	{parenth_ferme++;}
		
		if(parenth_ouvert<parenth_ferme)	{return -1;}
		
		if((parenth_ouvert == parenth_ferme) && !indice)	{indice = pos;}
		
		pos++;
	}
	
	if(parenth_ouvert > parenth_ferme)	{return -1;}
	
	else return indice;
	
}

int parenthese(char *s)
{
	int i = 1;
	int cmpt = 1;
	
	while(s[i] != '\0')
	{
		if(s[i]=='(')	{cmpt ++;}
		if(s[i]==')')	{cmpt --;}
		if(cmpt==0)	{return i;}
		i++;
	}
	return -1;
}

