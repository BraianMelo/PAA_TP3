#include "../include/KMP.h"

void calcular_prefixo(char *sub_string, int m, int *prefixo) {
    int j = 0;
    prefixo[0] = 0;

    for (int i = 1; i < m; ++i) {
        while (j > 0 && sub_string[i] != sub_string[j]) {
            j = prefixo[j - 1];
        }

        if (sub_string[i] == sub_string[j]) {
            ++j;
        }

        prefixo[i] = j;
    }
}

bool kmp(char *string, char *sub_string, int ini_intervalo, int fim_intervalo) {
    int m = strlen(sub_string);
    int n = fim_intervalo - ini_intervalo + 1;

    // Verifica se o padrão é maior que o intervalo
    if (m > n) {
        return false;
    }

    int prefixo[m];
    calcular_prefixo(sub_string, m, prefixo);

    int j = 0;
    for (int i = ini_intervalo; i <= fim_intervalo; ++i) {
        while (j > 0 && string[i] != sub_string[j]) {
            j = prefixo[j - 1];
        }

        if (string[i] == sub_string[j]) {
            ++j;
        }

        if (j == m) { // Achou a sub_string
            return true;
        }
    }

    return false;
}
