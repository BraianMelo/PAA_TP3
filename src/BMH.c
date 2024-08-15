#include "../include/BMH.h"

bool BMH(char *string, char *sub_string, int ini_intervalo, int fim_intervalo) {
    int m = strlen(sub_string);
    int n = fim_intervalo - ini_intervalo + 1;

    // Verifica se o padrão é maior que o intervalo
    if (m > n) {
        return false;
    }

    // Tabela de deslocamento
    int d[ALFABETO];
    for (int i = 0; i < ALFABETO; ++i) {
        d[i] = m;
    }
    for (int i = 0; i < m - 1; ++i) {
        d[(unsigned char)sub_string[i]] = m - i - 1;
    }

    int j = m - 1 + ini_intervalo;
    while (j <= fim_intervalo) { // Buscando a sub_string
        int k = j;
        int i = m - 1;

        while (i >= 0 && string[k] == sub_string[i]) {
            --k;
            --i;
        }

        if (i < 0) { // Achou a sub_string
            return true;
        }

        j += d[(unsigned char)string[j]];
    }

    return false;
}
