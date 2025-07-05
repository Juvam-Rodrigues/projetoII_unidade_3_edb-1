#ifndef FILA_LEITOS_H //Leitos
#define FILA_LEITOS_H


#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"


#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 10

typedef struct {
    Paciente pacientes[TAMANHO_MAX];
    int tamanho;
} Fila;

void inicializar_fila(Fila *fila);
int fila_vazia(Fila *fila);
int fila_cheia(Fila *fila);
void inserir_fila(Fila *fila, Paciente valor);
Paciente remover_fila(Fila *fila);
Paciente consultar_primeiro(Fila *fila);
void exibir_fila(Fila *fila);

#endif