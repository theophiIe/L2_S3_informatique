struct Expression_Arithmetique {
	int types; 	//0->float//1->+//2->*//
	float val;
	struct Expression_Arithmetique *FilsG;
	struct Expression_Arithmetique *FilsD;
};
typedef struct Expression_Arithmetique *EA;

EA stringn_to_EA(char *s, int g, int d);
