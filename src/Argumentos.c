#include "../include/Argumentos.h"

bool Receber_Argumentos(int argc, char *argv[], char *tipo, char **caminho_arq_entrada)
{

    if (argc != 3)
    {
        printf("Números de argumentos inválido! \n");
        printf("./tp3 <estrategia> entrada.txt \n");
        printf("São necessarios 3 argumentos, você passou %d argumentos! \n", argc);
        return false;
    }

    *tipo = argv[1][0];

    if (*tipo == 'F' || *tipo == 'f')
    {
        *tipo = 'F';
    }
    else if (*tipo == 'B' || *tipo == 'b')
    {
        *tipo = 'B';
    }
    else if (*tipo == 'K' || *tipo == 'k')
    {
        *tipo = 'K';
    }
    else
    {
        printf("Erro. Esse metodo nao existe! \nApenas os seguintes algoritmos foram implementados: \n");
        printf("+  'F' ou 'f': Forca Bruta \n");
        printf("+  'B' ou 'b': Boyer-Moore-Horspool \n");
        printf("+  'K' ou 'k': Knuth-Morris-Pratt \n");
        return false;
    }

    *caminho_arq_entrada = argv[2];

    return true;
}

bool Testar_Intervalo(char *string, char *sub_string, int inicio_intervalo, int fim_intervalo) {
    int tam_string = strlen(string);
    int tam_sub_string = strlen(sub_string);

    if (inicio_intervalo < 0 || fim_intervalo >= tam_string) 
        return false;

    int tam_intervalo = fim_intervalo - inicio_intervalo + 1;

    if (tam_intervalo <= 0 || tam_intervalo < tam_sub_string)
        return false;

    return true;
}


bool Abrir_Arquivos(char **caminho_arq_entrada, FILE **arquivo_entrada, FILE **arquivo_saida)
{

    *arquivo_entrada = fopen(*caminho_arq_entrada, "r");

    if (*arquivo_entrada == NULL)
    {
        printf("Arquivo de entrada não existe! \n");
        return false;
    }

    *arquivo_saida = fopen(CAMINHO_ARQ_SAIDA, "w");

    if (*arquivo_saida == NULL)
    {
        printf("Erro criando/abrindo arquivo de saída! \n");
        fclose(*arquivo_entrada);
        return false;
    }

    return true;
}

bool Fechar_Arquivos(FILE **arquivo_entrada, FILE **arquivo_saida)
{
    if (*arquivo_entrada == NULL)
        return false;
    fclose(*arquivo_entrada);

    if (*arquivo_saida == NULL)
        return false;
    fclose(*arquivo_saida);

    return true;
}
