#include "../include/pilha.h"
#include "../include/paciente.h"

void push(Pilha* p, Paciente *paciente) {
  if(p->topo < TAM_MAX-1){
    p->pacientesAlta[++p->topo] = paciente;
  }else{
    printf("Erro: Pilha cheia!\n");
  }
}

int esta_vazia(Pilha *p){
  return p->topo == -1;
}

Paciente* pop(Pilha *p){
  if(!esta_vazia(p)){
    Paciente *pacienteLiberado = copiar_paciente(p->pacientesAlta[p->topo]);
    liberar_paciente(p->pacientesAlta[p->topo]);
    
    p->topo --;
    return pacienteLiberado;
  }

  printf("Erro: Pilha vazia!\n");

  Paciente *pacienteVazio = NULL;
  return pacienteVazio;
}

Paciente* peek(Pilha *p){
  if(p->topo >= 0){
    return p->pacientesAlta[p->topo];
  }

  printf("Erro: Pilha vazia!\n");
    
  return NULL;
}
