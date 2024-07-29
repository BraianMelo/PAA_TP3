#include <stdio.h>
#include <string.h>

#define N 1024
#define M 10

void tirar_barra_N(char *string);

int main(){

    char string[N], sub_string[M];
    int K, inicio_intervalo, fim_intervalo;

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



    return 0;
}

void tirar_barra_N(char *string){
    int tamanho = strlen(string);
    string[tamanho - 1] = '\0';
}