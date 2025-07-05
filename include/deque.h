#ifndef DEQUE_H //Fila de espera
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "tabela.h"

#define TAMANHO 50

typedef struct NoDeque{
  Paciente paciente;
  struct NoDeque *proximo;
  struct NoDeque *anterior;
}NoDeque;

typedef struct Deque{
  NoDeque *inicio;
  NoDeque *final;
  int tamanho;
}Deque;

void inicia_deque(Deque *d);
void insere_inicio(Deque *d, Paciente paciente);
void insere_final(Deque *d, Paciente paciente);
Paciente remove_inicio(Deque *d);
Paciente remove_final(Deque *d);
Paciente pega_inicio(Deque *d);
Paciente pega_final(Deque *d);
int esta_vazio(Deque *d);
void imprime(Deque *d);

#endif
