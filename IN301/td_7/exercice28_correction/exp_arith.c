#include "exp_arith.h"
#include "chaine.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

EA strtoea(char *s){
	EA racine = malloc(sizeof(struct Expression_Arithmetique));
	if(s[0] != '('){ //case of a float
		racine->type = 0;
		racine->val = strtof(s,NULL);
	}
	else{//case of an operator
		int pos = parenthese(s);
		if(pos == -1){printf("Erreur dans la chaine de caractères"); return NULL;}
		if(s[pos+1] == '+') racine->type = 1;
		if(s[pos+1] == '*') racine->type = 2;
		if(s[pos+1] == '-') racine->type = 3;
		if(s[pos+1] == '/') racine->type = 4;
		racine->filsg = strtoea(s+1);
		racine->filsd = strtoea(s+pos+3);
	}
	return racine;
}

float eval(EA expr){
	if(expr != NULL){
		if(expr->type == 0)	return expr->val;
		if(expr->type == 1)	return eval(expr->filsd) + eval(expr->filsg);
		if(expr->type == 2)	return eval(expr->filsd) * eval(expr->filsg);
		if(expr->type == 3)	return eval(expr->filsd) - eval(expr->filsg);
	}
	return 0;
}

int taille_memoire(EA expr){
	if(expr == NULL) return 0;
	if( expr -> type == 0) return 20;//taille pour afficher un float
	return 5 + taille_memoire(expr->filsg) + taille_memoire(expr->filsd);
}

void afficheEA(EA a){
	if(a->type == 0) printf("(%f)",a->val);
	else{
		printf("(");
		afficheEA(a->filsg);
		printf(")");
		if(a->type == 1) printf("+");
		if(a->type == 2) printf("*");
		if(a->type == 3) printf("-");
		printf("(");
		afficheEA(a->filsd);
		printf(")");
	}
}

EA simplifie(EA expr){
	//addition par 0
	if(expr->type == 1){
		if(expr->filsg->type == 0 && expr->filsg -> val == 0)
		{
			return simplifie(expr->filsd);
		}
		if(expr->filsd->type == 0 && expr->filsd -> val == 0)
		{
			return simplifie(expr->filsg);
		}
	}
	
	//multiplication par 0
	if(expr->type == 2){
		if(expr->filsg->type == 0 && expr->filsg -> val == 0)
		{
			return expr->filsg;
		}
		if(expr->filsd->type == 0 && expr->filsd -> val == 0)
		{
			return expr->filsd;
		}
	}

	if(expr->type > 0){
		expr->filsg = simplifie(expr->filsg);
		expr->filsd = simplifie(expr->filsd);
	}
	return expr;
}

int max(int a, int b){
	return (a<b) ? b : a;
}

int hauteur(EA expr){
	return (!expr) ? 0 : 1 + max(hauteur(expr->filsg),hauteur(expr->filsd));
}

EA simplifie_vraiment(EA expr){
	int h = hauteur(expr);
	for(int i = 0; i<h; i++) expr = simplifie(expr);
	return expr;
}

//A FINIR
/**
char *eatostr(EA expr){
	char *s = malloc(taille_memoire(expr)*sizeof(char));
}

int parcours_infixe(EA expr, char *s){
	int decalage =0;
	if(a->type == 0) decalage = sprintf(s,"(%f)",a->val);
	else{
		sprintf(s,"(");
		decalage = 1 + parcours_infixe(a->filsg,s+1);
		sprintf(s+decalage,")");
		decalage++;
		sprintf(s,"%c",(a->type == 1) ? '+' : '*');
		sprintf(s,"(");
		parcours_infixe(a->filsd,s);
		sprintf(s,")");
	}
}
*/


