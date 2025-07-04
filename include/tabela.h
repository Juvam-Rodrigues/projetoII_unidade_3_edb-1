#ifndef TABELA_H
#define TABELA_H

#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

#define TAMANHO 50

typedef struct No{
  Paciente paciente;
  struct No *proximo;
} No;

typedef struct Tabela{
  No *tabela[TAMANHO];
}Tabela;

void percorrerArquivo(char* Arquivo);

#endif
