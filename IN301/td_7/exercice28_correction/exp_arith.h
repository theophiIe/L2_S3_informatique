struct Expression_Arithmetique {
	int type; //0 for a float, 1 for a +, 2 for a *
	float val;
	struct Expression_Arithmetique *filsg;
	struct Expression_Arithmetique *filsd;
};

typedef struct Expression_Arithmetique *EA;

EA strtoea(char *s);
void afficheEA(EA a);
float eval(EA expr);
EA simplifie(EA expr);
EA simplifie_vraiment(EA expr);
