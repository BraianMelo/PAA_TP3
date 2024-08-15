#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/Tempo.h"
#include "../include/Forca_Bruta.h"
#include "../include/BMH.h"
#include "../include/KMP.h"

#define CAMINHO_ARQ_SAIDA "data/saida.txt"

#define N 1024
#define M 10

bool receber_Argumentos(int argc, char *argv[], char *tipo, char **arquivo_de_entrada);
bool abrir_Arquivos(char **caminho_arq_entrada, FILE **arquivo_entrada, FILE **arquivo_saida);
bool fechar_Arquivos(FILE **arquivo_entrada, FILE **arquivo_saida);

int main(int argc, char *argv[]){

  // Criacao de variaveis
  struct timeval ini_tempo_total, fim_tempo_total;
  struct rusage inicio, fim;

  char tipo, *caminho_arq_entrada;
  FILE *arquivo_entrada, *arquivo_saida;

  char string[N], sub_string[M];
  int K, inicio_intervalo, fim_intervalo;

  // Testando se os argumentos foram passados corretamente
  if(!receber_Argumentos(argc, argv, &tipo, &caminho_arq_entrada))
    return 1;

  // Testando se o arquivo de entrada existe
  if(!abrir_Arquivos(&caminho_arq_entrada, &arquivo_entrada, &arquivo_saida))
    return 1;

  // Inicio da cronometragem
  iniciar_contagem(&ini_tempo_total, &inicio); 

  fscanf(arquivo_entrada, "%s", string);
  fscanf(arquivo_entrada, "%s", sub_string);
  
  fscanf(arquivo_entrada, "%d", &K);

  for (int i = 0; i < K; ++i) {
    fscanf(arquivo_entrada, "%d", &inicio_intervalo);
    fscanf(arquivo_entrada, "%d", &fim_intervalo);

    inicio_intervalo -= 1;
    fim_intervalo -= 1;

    bool resultado = false;

    switch (tipo) {
      case 'F': // Forca bruta
        resultado = forca_Bruta(string, sub_string, inicio_intervalo, fim_intervalo);
        break;

      case 'B': // BMH
        resultado = bmh(string, sub_string, inicio_intervalo, fim_intervalo); // 2 erro aqui
        break;

      case 'K':
        resultado = kmp(string, sub_string, inicio_intervalo, fim_intervalo);
        break;

      default: // Algum erro aqui
        printf("Esse método não existe!");
        parar_contagem(&fim_tempo_total, &fim); 
        fechar_Arquivos(&arquivo_entrada, &arquivo_saida);        
        return 1;
    }

    if(resultado)
      fprintf(arquivo_saida, "sim\n");
    
    else
      fprintf(arquivo_saida, "nao\n");

  }

  parar_contagem(&fim_tempo_total, &fim); // Termina a cronometragem
  printar_tempo_gasto(&ini_tempo_total, &inicio, &fim_tempo_total, &fim); // Imprime os tempos no terminal

  fechar_Arquivos(&arquivo_entrada, &arquivo_saida); // Fecha os arquivos

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

  if (*tipo == 'F' || *tipo == 'f') {
    *tipo = 'F';

  } else if (*tipo == 'B' || *tipo == 'b') {
    *tipo = 'B';

  } else if (*tipo == 'K' || *tipo == 'k') {
    *tipo = 'K';

  } else {
    printf("Erro. Esse metodo nao existe! \nApenas os seguintes algoritmos foram implementados: \n");
    printf("+  'F' ou 'f': Forca Bruta \n");
    printf("+  'B' ou 'b': Boyer-Moore-Horspool \n");
    printf("+  'K' ou 'k': Knuth-Morris-Pratt \n");
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
