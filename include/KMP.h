#ifndef KMP_H
    #define KMP_H

    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h> // Foi usado apenas o strlen() 

    void Construir_Tabela_Prefixo(char *sub_string, int m, int *tabela_prefixo);
    bool KMP(char *string, char *sub_string, int ini_intervalo, int fim_intervalo);

#endif