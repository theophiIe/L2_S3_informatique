#include <stdio.h>
#include <stdlib.h>
#include "exp_arith.h"

EA stringn_to_EA(char *s, int g, int d)
{
	int pos = parenthese(s+g);
	
	if(pos == 1)
	{
		printf("Erreur");
	}
	return NULL;
	
}
