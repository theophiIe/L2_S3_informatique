#include "pile.h"

typedef Pile File;



//remplit une pile avec n valeurs entre 1 et k
Pile remplir_pile(int n, int k){
  Pile p = creer_pile();
  int i;

  for(i=0; i<n; i++)
    p = push(p, 1+rand()%k);
  return p;
}


void affiche_pile(Pile p){
  while(!est_vide(p)){
    printf("%d\n", pick(p));
    p = pop(p);
  }
  printf("#######################################\n");
}


//Question a
Pile inverse(Pile p){
  Pile pres = creer_pile();

while(!est_vide(p))
{
	pres=push(pres,pick(p));
	p=pop(p);
}  
  return pres;
}


//Question b
Pile un_sur_deux(Pile p){
  Pile pres = creer_pile();
int i=0;
while(!est_vide(p))
{
	if(i%2==0)
	{
		pres=push(pres,pick(p));
		p=pop(p);
	}
	
	if(i%2==1)
	{
		p=pop(p);
	}
	i++;
}
  return inverse(pres);
}

//Question c
void  partition_parite(Pile p, Pile* ppair, Pile* pimpair){

	while(!est_vide(p))
	{
		if(pick(p)%2==0)
		{
			*ppair=push(*ppair,pick(p));
		
		}
		
		else 
		{
			*pimpair=push(*pimpair,pick(p));
			
		}
		p=pop(p);
	}
  
}



//Question d
void  partition_parite2(Pile* p, Pile* pimpair){

  //TODO
  
}




//Question e
/*
File creer_file(){

}

int est_file_vide(File f){

}

File enfiler(File f, int v){
  
}

int tete(File f){

}

File defiler(File f){

}
*/


int main(){
  Pile p, p12, pinv, ppair, pimpair;
  File f;
  ppair= creer_pile();
  pimpair = creer_pile();

  p = remplir_pile(15, 50);
  printf("Pile principale:\n");
  affiche_pile(p);

  
  //Question a
  pinv = inverse(p);
  printf("Pile inverse:\n");
  affiche_pile(pinv);

  
  //Question b
  p12 = un_sur_deux(p);
  printf("Pile un sur deux:\n");
  affiche_pile(p12);

  
  //Question c
  partition_parite(p, &ppair, &pimpair);
  printf("Pile paire1:\n");
  affiche_pile(ppair);
  printf("Pile impaire1:\n");
  affiche_pile(pimpair);


  //Question d
  partition_parite2(&p, &pimpair);
  printf("Pile paire2:\n");
  affiche_pile(p);
  printf("Pile impaire2:\n");
  affiche_pile(pimpair);


  
  
  //Question e
  /*
  f = creer_file();
  f = enfiler(f, 5);
  f = enfiler(f, 2);
  f = enfiler(f, 3);
  printf("File1:\n");
  affiche_pile(f);
  f = defiler(f);
  printf("File2:\n");
  affiche_pile(f);
  */
  
  exit(EXIT_SUCCESS);
}
