#ifndef TABELA_H
#define TABELA_H

#include <stdio.h> //Triagem
#include <stdlib.h>
#include "paciente.h"

#define TAMANHOTABELA 50

typedef struct NoTabela
{
  Paciente paciente;
  struct NoTabela *proximo;
} NoTabela;

typedef struct Tabela
{
  NoTabela *tabela[TAMANHOTABELA];
  int tamanho;
} Tabela;

void inicializar_tabela(Tabela *tabela);
int funcao_hash(int chave);
int sortear_posicao(Tabela *tabel);
Paciente* buscar_paciente_tabela(Tabela *tabela, int numeroSorteado);
int preencherPacientes(Tabela *tabel, char *nomeArquivo);
NoTabela *criar_no(Paciente paciente);
void inserir(Tabela *tabela, Paciente paciente, int chave);
void imprimir_tabela(Tabela *tabela);

#endif
