#include "../include/Forca_Bruta.h"

bool Forca_Bruta(char *string, char *sub_string, int ini_intervalo, int fim_intervalo) {
    int tam_string = strlen(string);
    int tam_sub_string = strlen(sub_string);

    // Verifica se o intervalo e o tamanho da sub-string são válidos
    if (tam_sub_string > (fim_intervalo - ini_intervalo + 1)) {
        return false;
    }

    for (int i = ini_intervalo; i <= fim_intervalo - tam_sub_string + 1; ++i) { // Itera pela String no intervalo
        int j;
        for (j = 0; j < tam_sub_string; ++j) { // Verifica se a sub_string está presente
            if (string[i + j] != sub_string[j]) {
                break;
            }
        }
        if (j == tam_sub_string) { // Todos os caracteres são iguais. Achou a sub-string!
            return true;
        }
    }

    return false;
}
