#include <stdio.h>
#include <stdlib.h>
#include "../include/fila_leitos.h"
#include "../include/paciente.h"

//-----------------------------------

void inicializar_fila(Fila* fila)
{
  fila->tamanho = 0;
}

//-----------------------------------

int fila_vazia(Fila* fila)
{
  return fila->tamanho == 0;
}

//-----------------------------------

int fila_cheia(Fila* fila)
{
  return fila->tamanho == TAMANHO_MAX;
}

//-----------------------------------

void inserir_fila(Fila* fila, Paciente paciente)
{
  if(fila_cheia(fila)){
    printf("Os leitos estão lotados!");
  }else{
    fila->pacientes[fila->tamanho] = paciente;
    fila->tamanho++;
  }
}

//-----------------------------------

Paciente remover_fila(Fila* fila)
{
  if(fila_vazia(fila)){
    printf("Os leitos estão vazios!\n");
    Paciente paciente_vazio;
    return paciente_vazio;
  }else{
    Paciente paciente = fila->pacientes[0];
 
    for (int i = 1; i < fila->tamanho; i++) {
      fila->pacientes[i - 1] = fila->pacientes[i];
    }
    fila->tamanho--;
    return paciente;
  }
}

//-----------------------------------

Paciente consultar_primeiro(Fila* fila)
{
  if(fila_vazia(fila)){
    printf("Os leitos estão vazios!\n");
    Paciente paciente_vazio;
    return paciente_vazio;
  }else{
    return fila->pacientes[0];
  }
}

//-----------------------------------

void exibir_fila(Fila* fila)
{
  if(fila_vazia(fila)){
    printf("Os leitos estão vazios!\n");
  }else{
    printf("Leitos: ");
    for(int i = 0; i < fila->tamanho; i++){
   exibir_paciente(fila->pacientes[i]);
    }
    printf("\n");
  }
}

//-----------------------------------
