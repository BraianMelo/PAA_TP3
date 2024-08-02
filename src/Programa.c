#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/Tempo.h"
#include "../include/Forca_Bruta.h"

#define CAMINHO_ARQ_SAIDA "data/saida.txt"

#define N 1024
#define M 10

bool receber_Argumentos(int argc, char *argv[], char *tipo, char **arquivo_de_entrada);
bool abrir_Arquivos(char **caminho_arq_entrada, FILE **arquivo_entrada, FILE **arquivo_saida);
bool fechar_Arquivos(FILE **arquivo_entrada, FILE **arquivo_saida);

int main(int argc, char *argv[]){

  char tipo, *caminho_arq_entrada;
  FILE *arquivo_entrada, *arquivo_saida;

  char string[N], sub_string[M];
  int K, inicio_intervalo, fim_intervalo;

  if(!receber_Argumentos(argc, argv, &tipo, &caminho_arq_entrada))
    return 1;

  if(!abrir_Arquivos(&caminho_arq_entrada, &arquivo_entrada, &arquivo_saida))
    return 1;

  struct timeval ini_tempo_total, fim_tempo_total;
  struct rusage inicio, fim;

  iniciar_contagem(&ini_tempo_total, &inicio);

  fscanf(arquivo_entrada, "%s", string);
  fscanf(arquivo_entrada, "%s", sub_string);
  
  fscanf(arquivo_entrada, "%d", &K);

  for (int i = 0; i < K; ++i) {
    fscanf(arquivo_entrada, "%d", &inicio_intervalo);
    fscanf(arquivo_entrada, "%d", &fim_intervalo);

    bool resultado = false;

    switch (tipo) {
      case 'B':
        resultado = forca_Bruta(string, sub_string, --inicio_intervalo, --fim_intervalo);
        break;
      
      default:
        printf("Esse método não existe ainda!\n");
        return 1;
        break;
    }

    if(resultado)
      printf("sim\n");
    else
      printf("nao\n");


  }

  parar_contagem(&fim_tempo_total, &fim);
  printar_tempo_gasto(&ini_tempo_total, &inicio, &fim_tempo_total, &fim);

  fechar_Arquivos(&arquivo_entrada, &arquivo_saida);

  return 0;
}

bool receber_Argumentos(int argc, char *argv[], char *tipo, char **caminho_arq_entrada) {

  if (argc != 3) {
    printf("Números de argumentos inválido!\n");
    printf("./tp3 <estrategia> entrada.txt\n");
    printf("São necessarios 3 argumentos, você passou apenas %d!\n", argc);
    return false;
  }

  *tipo = argv[1][0];

  if (*tipo == 'B' || *tipo == 'b') {
    *tipo = 'B';

  } else if (*tipo == 'A' || *tipo == 'a') {
    *tipo = 'a';

  } else {
    printf("Erro! Use apenas A ou B para indicar o método.\n");
    return false;
  }

  *caminho_arq_entrada = argv[2];

  return true;
}

bool abrir_Arquivos(char **caminho_arq_entrada, FILE **arquivo_entrada, FILE **arquivo_saida){

        *arquivo_entrada = fopen(*caminho_arq_entrada, "r");

        if(*arquivo_entrada == NULL){
                printf("Arquivo de entrada não existe! \n");
                return false;
        }

        *arquivo_saida = fopen(CAMINHO_ARQ_SAIDA, "w");

        if(*arquivo_saida == NULL){
                printf("Erro criando/abrindo arquivo de saída! \n");
                fclose(*arquivo_entrada);
                return false;
        }

        return true;
}

bool fechar_Arquivos(FILE **arquivo_entrada, FILE **arquivo_saida){
        if(*arquivo_entrada == NULL)
                return false;
        fclose(*arquivo_entrada);

        if(*arquivo_saida == NULL)
                return false;
        fclose(*arquivo_saida);

        return true;
}
