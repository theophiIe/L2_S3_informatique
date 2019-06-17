run: tri_bulle tri_fusion
	./tri_bulle
	./tri_fusion


# Le tri fusion
tri_fusion: tri_fusion.o tabint.o
	gcc -Wall -o tri_fusion tri_fusion.o tabint.o

tri_fusion.o: tri_fusion.c tabint.h
	gcc -Wall -c tri_fusion.c

# Le tri à bulles
tri_bulle: tri_bulle.o tabint.o
	gcc -Wall -o tri_bulle tri_bulle.o tabint.o

tri_bulle.o: tri_bulle.c tabint.h
	gcc -Wall -c tri_bulle.c


# La bibliothèque de maniupulation de tableaux
tabint.o: tabint.c tabint.h
	gcc -Wall -c tabint.c


geany:
	geany *.c *.h Makefile&

clean: cleanprog cleandata
	ls -l

cleanprog:
	rm -f tabint.o
	rm -f tri_bulle.o tri_bulle
	rm -f tri_fusion.o tri_fusion

cleandata:
#	rm -f *.data
#	rm -f *.pdf


ZIPNAME=IN301_TD5
zip:
	rm -rf ${ZIPNAME}
	mkdir ${ZIPNAME}
	cp *.c ${ZIPNAME}
	cp *.h ${ZIPNAME}
	cp Makefile ${ZIPNAME}
	cp *.gplt ${ZIPNAME}
	zip -r $(ZIPNAME).zip $(ZIPNAME)
	rm -rf ${ZIPNAME}
	ls -l ${ZIPNAME}*
