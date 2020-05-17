run: compile
	./test \(\(0.1\)-\(2.23\)\)*\(0\)
	./test \(\(0\)-\(2.23\)\)*\(5.0\)
		
compile: test.o exp_arith.o chaine.o
	gcc test.o exp_arith.o chaine.o -o test -lm

test.o: test.c exp_arith.h chaine.h
	gcc -c test.c -Wall

exp_arith.o: exp_arith.c exp_arith.h
	gcc -c exp_arith.c -Wall

chaine.o: chaine.c 
	gcc -c chaine.c -Wall

clean:
	rm -f *.o
	rm -f test
