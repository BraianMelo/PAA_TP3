#ifndef ARGUMENTOS_H

    #define ARGUMENTOS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #define CAMINHO_ARQ_SAIDA "data/saida.txt"

    /* Esse arquivo foi criado para lidar com a abertura e fechamento dos arquivos
        e com os argumentos fornecidas pelo usuario.                                */

    bool Receber_Argumentos(int argc, char *argv[], char *tipo, char **arquivo_de_entrada);
    bool Abrir_Arquivos(char **caminho_arq_entrada, FILE **arquivo_entrada, FILE **arquivo_saida);
    bool Fechar_Arquivos(FILE **arquivo_entrada, FILE **arquivo_saida);

#endif