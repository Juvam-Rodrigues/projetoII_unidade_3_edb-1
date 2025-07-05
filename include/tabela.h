#ifndef TABELA_H
#define TABELA_H

#include <stdio.h> //Triagem
#include <stdlib.h>
#include "paciente.h"

#define TAMANHO 50

typedef struct No
{
  Paciente paciente;
  struct No *proximo;
} No;

typedef struct Tabela
{
  No *tabela[TAMANHO];
  int tamanho;
} Tabela;

void inicializar_tabela(Tabela *tabela);
int funcao_hash(int chave);
int sortear_posicao(Tabela *tabel);
int preencherPacientes(Tabela *tabel, char *nomeArquivo);
No *criar_no(Paciente paciente);
void inserir(Tabela *tabela, Paciente paciente, int chave);
void imprimir_tabela(Tabela *tabela);

#endif
