#include <stdio.h>
#include <stdlib.h>
#include "chaines.h"
#include "exp_arith.h"

int main(int argc, char** argv)
{
	printf("La position de la parenthese fermante est: %d \n",parenthese("(3*(2+2))"));
	
return 0;
}
