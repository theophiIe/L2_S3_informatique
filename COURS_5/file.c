#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "liste.h"

File creer_file(){
	return NULL;
}

int est_file_vide(File f){
  if(f==NULL)
	return 1;
  else
	return 0;
}

File enfile(File f, int v){
	return insere_fin(f,v);
}

File defile(File f){
	return supprime_deb(f);
}

int tete(File f){
	  if(est_file_vide(f)){
	  exit(EXIT_FAILURE);
	 }
  return f->val;
}

void affiche_file(File f){
	affiche_liste(f);
}
