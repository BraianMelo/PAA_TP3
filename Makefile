all: obj/Programa.o obj/Tempo.o
	gcc obj/Programa.o obj/Tempo.o -o tp3
	mv tp3 bin/

obj/Programa.o: src/Programa.c
	gcc -c src/Programa.c
	mv Programa.o obj/

obj/Tempo.o: src/Tempo.c include/Tempo.h
	gcc src/Tempo.c -c
	mv Tempo.o obj/

delete:
	rm obj/*.o
	rm bin/*
