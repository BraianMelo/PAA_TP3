#ifndef TEMPO_H

    #define TEMPO_H

    #include <stdio.h>
    #include <sys/time.h>
    #include <sys/resource.h>

    typedef struct timeval timeval;
    typedef struct rusage rusage;

    void Iniciar_Contagem(struct timeval *ini_tempo_total, struct rusage *inicio);
    void Parar_Contagem(struct timeval *fim_tempo_total, struct rusage *fim);
    void Imprimir_Tempo_Gasto(struct timeval *ini_tempo_total, struct rusage *inicio, struct timeval *fim_tempo_total, struct rusage *fim);

    float diffUserTime(struct rusage *inicio, struct rusage *fim);
    float diffSystemTime(struct rusage *inicio, struct rusage *fim);
    float diffRealTime(struct timeval *inicio, struct timeval *fim);

#endif