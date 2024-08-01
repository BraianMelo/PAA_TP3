#include <stdio.h>
#include <string.h> // Foi usado apenas o strlen() para tirar o '\n' que o fgets() captura
#include <stdlib.h>

#include "../include/Tempo.h"

#define N 1024
#define M 10

void tirar_barra_N(char *string);

int main(){

  char string[N], sub_string[M];
  int K, inicio_intervalo, fim_intervalo;

  struct timeval ini_tempo_total, fim_tempo_total;
  struct rusage inicio, fim;

  iniciar_contagem(&ini_tempo_total, &inicio);

  fgets(string, sizeof(string), stdin);
    fgets(sub_string, sizeof(sub_string), stdin);

    tirar_barra_N(string);
    tirar_barra_N(sub_string);

    scanf("%i", &K);

    for(int i = 0; i < K; ++i){
        scanf("%i %i", &inicio_intervalo, &fim_intervalo);
    }

    printf("%s\n", string);
    printf("%s\n", sub_string);

  parar_contagem(&fim_tempo_total, &fim);
  printar_tempo_gasto(&ini_tempo_total, &inicio, &fim_tempo_total, &fim);

    return 0;
}

void tirar_barra_N(char *string){
    int tamanho = strlen(string);
    string[tamanho - 1] = '\0';
}
