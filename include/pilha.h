#ifndef PILHA_H //Histórico
#define PILHA_H

#define TAM_MAX 100
#include "paciente.h"

typedef struct Pilha{
    Paciente *pacientesAlta[TAM_MAX];
    int topo;
}Pilha;

int esta_vazia(Pilha *p);
void push(Pilha* p, Paciente *paciente);
Paciente* pop(Pilha *p);
Paciente* peek(Pilha *p);


#endif

