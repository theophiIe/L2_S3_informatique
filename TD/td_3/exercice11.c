#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Taille int	 %ld \n",sizeof(int));
	printf("Taille char	 %ld \n",sizeof(char));
	printf("Taille double	 %ld \n",sizeof(double));
	printf("Taille char*	 %ld \n",sizeof(char*));
	printf("Taille void*	 %ld \n",sizeof(void*));
	printf("Taille int*	 %ld \n",sizeof(int*));
	printf("Taille double*	 %ld \n",sizeof(double*));
	printf("Taille int**	 %ld \n",sizeof(int**));
	printf("Taille int[10]	 %ld \n",sizeof(int[10]));
	printf("Taille int[7][3] %ld \n",sizeof(int[7][10]));
	
float tab[10];

	printf("Taille tab	 %ld \n",sizeof(tab));
	printf("Taille tab[0]	 %ld \n",sizeof(tab[0]));
	printf("Taille &tab[0]	 %ld \n",sizeof(&tab[0]));
	printf("Taille *&tab	 %ld \n",sizeof(*&tab));
	printf("Taille *&tab[0]	 %ld \n",sizeof(*&tab[0]));
	
return 0;
}
