#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "chaine.h"
#include "exp_arith.h"


int main(int argc, char **argv){
	if(argc == 1) {printf("Je veux un argument");}
	else{
		printf("Chaine: %s \nPosition de la parenthèse %d \n",argv[1],parenthese(argv[1]));
		EA mon_expr = strtoea(argv[1]);
		afficheEA(mon_expr);
		printf("\n");
		printf("valeur de l'arbre %f \n",eval(mon_expr));
		mon_expr = simplifie(mon_expr);
		afficheEA(mon_expr);
		printf("\n");
				
		mon_expr = simplifie_vraiment(mon_expr);
		afficheEA(mon_expr);
		printf("\n");
	}

	return 0;
}
