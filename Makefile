all: obj/Programa.o obj/Tempo.o obj/Forca_Bruta.o obj/BMH.o obj/KMP.o
	gcc obj/Programa.o obj/Tempo.o obj/Forca_Bruta.o obj/BMH.o obj/KMP.o -o tp3
	mv tp3 bin/

obj/Programa.o: src/Programa.c
	gcc -c src/Programa.c
	mv Programa.o obj/

obj/Tempo.o: src/Tempo.c include/Tempo.h
	gcc src/Tempo.c -c
	mv Tempo.o obj/

obj/Forca_Bruta.o: src/Forca_Bruta.c include/Forca_Bruta.h
	gcc src/Forca_Bruta.c -c
	mv Forca_Bruta.o obj/

obj/BMH.o: src/BMH.c
	gcc src/BMH.c -c
	mv BMH.o obj/

obj/KMP.o: src/KMP.c 
	gcc src/KMP.c -c
	mv KMP.o obj/

delete:
	rm obj/*.o
	rm bin/*
