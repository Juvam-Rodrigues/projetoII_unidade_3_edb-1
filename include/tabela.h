#ifndef TABELA_H
#define TABELA_H

#include <stdio.h> //Triagem
#include <stdlib.h>
#include "paciente.h"

#define TAMANHOTABELA 50

typedef struct NoTabela
{
  Paciente *paciente;
  struct NoTabela *proximo;
} NoTabela;

typedef struct Tabela
{
  NoTabela *tabela[TAMANHOTABELA];
  int tamanho;
} Tabela;

//Parte de inserir
void inicializar_tabela(Tabela *tabela);
int preencher_pacientes(Tabela *tabel, char *nomeArquivo);
int funcao_hash(int chave);
void inserir_tabela(Tabela *tabela, Paciente paciente, int chave);
NoTabela *criar_no(Paciente paciente);

//Parte de sortear
int sortear_posicao(Tabela *tabel);
Paciente* buscar_paciente_tabela(Tabela *tabela, int numeroSorteado);

//Imprime tabela
void imprimir_tabela(Tabela *tabela);

#endif
