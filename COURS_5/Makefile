run: pile
	./pile

pile: main.o chrono.o  pile.o liste.o file.o
	gcc -Wall -o pile main.o chrono.o pile.o liste.o file.o

pile.o: pile.c pile.h
	gcc -Wall -c pile.c 

main.o: main.c pile.h chrono.h 
	gcc -Wall -c main.c 

chrono.o: chrono.c 
	gcc -Wall -c chrono.c 

liste.o: liste.c liste.h
	gcc -c liste.c -Wall

file.o: file.c file.h
	gcc -c file.c -Wall
	
clean:
	rm -f *.o
	rm -f pile
	ls -l

