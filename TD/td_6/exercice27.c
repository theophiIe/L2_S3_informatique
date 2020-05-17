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

//QUESTION EXERCICE 24//
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



//QUESTION EXERCICE 25//

struct liste *inserer_fin_iter (struct liste *l, int val)
{
	struct liste *t = malloc(sizeof(struct liste));
	t -> val = val;
	t -> suiv = NULL;
	
	if(l==NULL)	{return t;}
	
	struct liste *ldeb=l;
	
	while(l -> suiv != NULL)	{l=l->suiv;}
	
	l -> suiv = t;
	
	return ldeb;
}

struct liste *inserer_fin_rec (struct liste *l, int val)
{	
	if(l==NULL)
	{
		return inserer_deb(l,val);
	}
	
	l -> suiv = inserer_fin_rec(l->suiv,val);

	return l;
}

struct liste *supprimer_fin_iter(struct liste *l)
{
	while((l->suiv)->suiv != NULL)
	{
		l=l->suiv;
	}
	
	free(l->suiv);
	l->suiv=NULL;
	
	return l;
}


//QUESTION EXERCICE 27//

struct liste *concat (struct liste *l1, struct liste *l2)
{
	struct liste *ldeb=l1;
		
		if(l1==NULL)
	{
		return l2;
	}
	
	while((l1->suiv) != NULL)
	{
		l1=l1->suiv;
	}
	
	l1->suiv=l2;
	
	return ldeb;
	
	
}

struct liste *fusion (struct liste *l1, struct liste *l2)
{
	struct liste *l3 = NULL;
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
	if((l1 -> val) < (l2 -> val))
	{
		l3 = l1;
		l1 = l1 -> suiv;
	}
	
	else
	{
		l3 = l2;
		l2 = l2 -> suiv;
	}
	
	struct liste *ldeb=l3;
	
	while(l1 != NULL && l2 != NULL)
	{
		if((l1->val) < (l2->val))
		{
			l3->suiv = l1;
			l3 = l3 -> suiv;
			l1 = l1 -> suiv;
		}
	
		else
		{
			l3->suiv = l2;
			l3 = l3 -> suiv;
			l2 = l2 -> suiv;
		}
	}
	if(l1==NULL) return concat(ldeb,l2);
	return concat(ldeb,l1);
}

struct liste *uniq (struct liste *l)
{
	if(l==NULL)	return NULL;
	struct liste *ldeb=l;
	struct liste *next;
	
	while(l->suiv != NULL)
	{
		if(l->val == (l->suiv)->val)
		{
			next = (l->suiv)->suiv;
			free(l->suiv);
			l->suiv=next;
		}
		
		else 
		{
			l= l->suiv;
		}
	}
	
	return ldeb;
}

//INT MAIN//
int main()
{
	struct liste *l=NULL;
	struct liste *l2=NULL;
	l=malloc(sizeof(struct liste));
	l -> val = 23;
	l -> suiv = NULL;

	struct liste *t;
	t=malloc(sizeof(struct liste));
	t -> suiv = l;
	t -> val = 42;
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

printf("EXERCICE 24 QUESTION a:\n");
	l=inserer_deb(l,4);
	affiche_rec(l);
	printf("\n");

printf("QUESTION b:\n");	
	inserer_deb2(&l,4);
	affiche_rec(l);
	printf("\n");

printf("QUESTION c:\n");	
	l=supprimer_deb(l);
	affiche_rec(l);
	printf("\n");
		

//QUESTION DE LA QUESTION 24//

printf("EXERCICE 25 QUESTION a:\n");
	inserer_fin_iter(l,25);
	affiche_rec(l);
	printf("\n");
	
	inserer_fin_rec(l,12);
	affiche_rec(l);
	printf("\n");
	
printf("QUESTION b:\n");
	supprimer_fin_iter(l);
	affiche_rec(l);
	printf("\n");

printf("EXERCICE 27 QUESTION b:\n");
	inserer_deb2(&l2,14);
	inserer_deb2(&l2,4);
	inserer_deb2(&l2,2);
	inserer_deb2(&l2,43);
	
	concat(l,l2);
	affiche_rec(l);
	printf("\n");	
	
printf("QUESTION c:\n");	
	fusion(l,l2);
	affiche_rec(l);
	printf("\n");
	
printf("QUESTION d:\n");	
	uniq(l);
	affiche_rec(l);
	printf("\n");
	
return 0;
}
