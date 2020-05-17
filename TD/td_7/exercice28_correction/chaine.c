int parenthese(char *s){
	int i = 1, cmpt = 1;
	while(s[i] != '\0'){
		if(s[i] == '(') cmpt++;
		if(s[i] == ')') cmpt--;
		if (cmpt == 0) return i;
		i++;
	}
	return -1;
}