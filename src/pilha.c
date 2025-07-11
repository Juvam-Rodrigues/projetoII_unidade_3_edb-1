#include "../include/pilha.h"
#include "../include/paciente.h"
#include "../include/log.h"

void push(Pilha *p, Paciente *paciente, Log *log)
{
  if (esta_cheia(p))
  {
    printf("Erro: Pilha cheia!\n");
  }
  else
  {
    p->pacientesAlta[++p->topo] = paciente;
    adicionar_paciente_alta_log(log, paciente);
  }
}

int esta_vazia(Pilha *p)
{
  return p->topo == -1;
}

int esta_cheia(Pilha *p)
{
  return p->topo == TAM_MAX - 1;
}

Paciente *pop(Pilha *p)
{
  if (!esta_vazia(p))
  {
    Paciente *pacienteLiberado = copiar_paciente(p->pacientesAlta[p->topo]);
    liberar_paciente(p->pacientesAlta[p->topo]);

    p->topo--;
    return pacienteLiberado;
  }

  printf("Erro: Pilha vazia!\n");

  Paciente *pacienteVazio = NULL;
  return pacienteVazio;
}

Paciente *peek(Pilha *p)
{
  if (p->topo >= 0)
  {
    return p->pacientesAlta[p->topo];
  }

  printf("Erro: Pilha vazia!\n");

  return NULL;
}

void liberar_pilha(Pilha *p)
{
  while (!esta_vazia(p))
  {
    Paciente *paciente = pop(p);
    free(paciente);
  }
  p->topo = -1;
}