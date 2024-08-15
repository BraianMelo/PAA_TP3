#include "../include/Forca_Bruta.h"

bool forca_Bruta(char *string, char *sub_string, int ini_intervalo, int fim_intervalo){
    int tam_string = strlen(string);
    int tam_sub_string = strlen(sub_string);

    int aux = 0;

    for(int i = ini_intervalo; i < fim_intervalo; ++i){ //Itera pela String no intervalo
        if(string[i] == sub_string[0]){ // Se o 1° caractere da string for igual ao 1° da sub_string
            aux = i + 1;

            for(int j = 1; j < tam_sub_string; ++j){ // Itera a partir daquele caractere para ver se a sub_string esta presente
                if(string[aux] != sub_string[j])
                    break;
                
                ++aux;
                if(j + 1 == tam_sub_string){ // Todos os caracteres são iguais. Achou a sub string!
                    return true;
                }
            }
            aux = 0;
        }
    }

    return false;
}