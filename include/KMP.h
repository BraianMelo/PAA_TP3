#ifndef KMP
#define KMP

#include <stdio.h>
#include <stdbool.h>
#include <string.h> // Foi usado apenas o strlen() 

void construirTabelaPrefixo(char *sub_string, int m, int *tabela_prefixo);
bool kmp(char *string, char *sub_string, int ini_intervalo, int fim_intervalo);

#endif