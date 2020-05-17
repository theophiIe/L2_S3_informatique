#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void affiche_iter(struct liste *l)
{
	while(l != NULL)
	{
		printf("%d\n",l -> val);
		l=l -> suiv;
	}	
}

void affiche_rec(struct liste *l)
{
	if(l != NULL)
	{
		printf("%d\n",l -> val);
		affiche_rec(l -> suiv);
	}
}

int nb_elem_iter(struct liste *l)
{
	int compteur=0;
	
	while(l != NULL)
	{
	compteur++;
	l=l -> suiv;
	}
	return compteur;
}

int  nb_elem_rec (struct liste *l)
{
	if(l != NULL)
	{
		return 1+ nb_elem_rec(l -> suiv);
	}
	
	return 0;
}

int est_present_iter(struct liste *l, int val)
{
	while(l !=NULL)
	{
		
		if(l -> val == val) return 1;
		l=l -> suiv;
	}
	
	return 0;
}

int est_present_rec(struct liste *l, int val)
{
	if(l != NULL) 
	{
		if(l->val ==val) return 1;

		else return 0 + est_present_rec(l -> suiv, val);
	}
	return 0;
}

//QUESTION DE LA QUESTION 24//
struct liste *inserer_deb(struct liste *l, int val)
{
	struct liste *t = malloc(sizeof(struct liste));
	t -> val = val;
	t -> suiv = l;
	
return t;
}

void inserer_deb2(struct liste **l, int val)
{
	struct liste *t = malloc(sizeof(struct liste));
	t -> val = val;
	t -> suiv = *l;	
	*l=t;
}

struct liste *supprimer_deb(struct liste *l)
{
	struct liste *tmp=l->suiv;
	free(l);
	return tmp;
}

//INT MAIN//
int main()
{
	struct liste *l=NULL;
	l=malloc(sizeof(struct liste));
	l -> val = 17;
	l -> suiv = NULL;

	struct liste *t;
	t=malloc(sizeof(struct liste));
	t -> suiv = l;
	t -> val = 23;
	l=t;
	
	struct liste *h;
	h=malloc(sizeof(struct liste));
	h -> val = 42;
	h -> suiv = l -> suiv;
	l -> suiv = h;
	
	affiche_iter(l);
	printf("\n");
	
	affiche_rec(l);
	printf("\n");
	
	printf("nombre d'element dans le tableau: %d\n",nb_elem_iter(l));
		
	printf("nombre d'element dans le tableau: %d\n",nb_elem_rec(l));
	printf("\n");
	
	if(est_present_iter(l,3)==1)	printf("valeur donnée: VRAI\n");
	
	else printf("valeur donnée: FAUX\n");
	
	if(est_present_rec(l,23)==1)	printf("valeur donnée: VRAI\n");
	
	else printf("valeur donnée: FAUX\n");

	printf("\n");
	
//QUESTION DE LA QUESTION 24//

printf("QUESTION a\n");
	l=inserer_deb(l,4);
	affiche_rec(l);
	printf("\n");

printf("QUESTION b\n");	
	inserer_deb2(&l,4);
	affiche_rec(l);
	printf("\n");

printf("QUESTION c\n");	
	l=supprimer_deb(l);
	affiche_rec(l);
	printf("\n");
		
return 0;
}
