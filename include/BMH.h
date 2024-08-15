#ifndef BMH_H
    #define BMH_H

    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h> // Foi usado apenas o strlen() 

    #define TAM_MAX 1000
    #define ALFABETO 256

    bool BMH(char *string, char *sub_string, int ini_intervalo, int fim_intervalo);

#endif
