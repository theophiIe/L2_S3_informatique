run: main
	./main test
	./main romeoetjuliette

all: main

main: main.o arbre.o 
	gcc main.o arbre.o -Wall -o main 

main.o: main.c arbre.h
	gcc -c main.c -Wall -g

arbre.o: arbre.c arbre.h
	gcc -c arbre.c -Wall -g

clean:
	rm *.o
	rm main
