all: obj/Programa.o
	gcc obj/Programa.o -o Programa
	mv Programa bin/

 obj/Programa.o: src/Programa.c
	gcc -c src/Programa.c
	mv Programa.o obj/