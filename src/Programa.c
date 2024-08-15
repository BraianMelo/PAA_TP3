#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/Argumentos.h"
#include "../include/Tempo.h"
#include "../include/Forca_Bruta.h"
#include "../include/BMH.h"
#include "../include/KMP.h"

#define N 1000000 // Tamanho maximo da String
#define M 10 // Tamanho maximo da sub String

int main(int argc, char *argv[]){

  // Criacao de variaveis
  struct timeval ini_tempo_total, fim_tempo_total;
  struct rusage inicio, fim;

  char tipo, *caminho_arq_entrada;
  FILE *arquivo_entrada, *arquivo_saida;

  char string[N], sub_string[M];
  int K, inicio_intervalo, fim_intervalo;

  // Testando se os argumentos foram passados corretamente
  if(!Receber_Argumentos(argc, argv, &tipo, &caminho_arq_entrada))
    return 1;

  // Testando se o arquivo de entrada e saida existem
  if(!Abrir_Arquivos(&caminho_arq_entrada, &arquivo_entrada, &arquivo_saida))
    return 1;

  // Inicio da cronometragem
  Iniciar_Contagem(&ini_tempo_total, &inicio); 

  fscanf(arquivo_entrada, "%s", string);
  fscanf(arquivo_entrada, "%s", sub_string);
  
  fscanf(arquivo_entrada, "%d", &K);

  bool resultado = false;

  for (int i = 0; i < K; ++i) {
    fscanf(arquivo_entrada, "%d", &inicio_intervalo);
    fscanf(arquivo_entrada, "%d", &fim_intervalo);

    inicio_intervalo -= 1;
    fim_intervalo -= 1;

    if(!Testar_Intervalo(string, sub_string, inicio_intervalo, fim_intervalo)){ // Aumenta bastante o tempo
      fprintf(arquivo_saida, "%d ate %d: Intervalo Invalido! \n", inicio_intervalo, fim_intervalo);
      continue;
    }

    resultado = false;

    switch (tipo) {
      case 'F': // Forca bruta
        resultado = Forca_Bruta(string, sub_string, inicio_intervalo, fim_intervalo);
        break;

      case 'B': // BMH
        resultado = BMH(string, sub_string, inicio_intervalo, fim_intervalo); // 2 erro aqui
        break;

      case 'K':
        resultado = KMP(string, sub_string, inicio_intervalo, fim_intervalo);
        break;

      default: // Existe apenas por existir, nao deve rodar nunca
        printf("Esse método não existe!");
        Parar_Contagem(&fim_tempo_total, &fim); 
        Fechar_Arquivos(&arquivo_entrada, &arquivo_saida);        
        return 1;
    }

    if(resultado)
      fprintf(arquivo_saida, "sim\n");
    
    else
      fprintf(arquivo_saida, "nao\n");

  }

  Parar_Contagem(&fim_tempo_total, &fim); // Termina a cronometragem
  Imprimir_Tempo_Gasto(&ini_tempo_total, &inicio, &fim_tempo_total, &fim); // Imprime os tempos no terminal

  Fechar_Arquivos(&arquivo_entrada, &arquivo_saida); // Fecha os arquivos

  return 0;
}