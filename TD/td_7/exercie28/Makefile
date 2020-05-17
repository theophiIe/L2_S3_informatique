run: compile
	./test
	
compile: exp_arith.o	chaines.o	test.o

	gcc exp_arith.o chaines.o test.o -o test

test.o: test.c 
	
	gcc -c -Wall test.c

