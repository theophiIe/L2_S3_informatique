run: pile
	./pile

pile: pile.o main.o
	gcc -Wall -o pile main.o pile.o


pile.o: pile.c pile.h
	gcc -Wall -c pile.c

main.o: main.c pile.h
	gcc -Wall -c main.c

clean:
	rm -f *.o
	rm -f pile
	ls -l

