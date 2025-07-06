#include <stdio.h>
#include <stdlib.h>
#include "../include/leitos.h"
#include "../include/paciente.h"
#include "../include/log.h"

//-----------------------------------

void inicializar_leitos(Leitos *leitos)
{
  leitos->tamanho = 0;
}

//-----------------------------------

int leitos_vazio(Leitos *leitos)
{
  return leitos->tamanho == 0;
}

//-----------------------------------

int leitos_cheio(Leitos *leitos)
{
  return leitos->tamanho == TAMANHO_MAX;
}

//-----------------------------------

void inserir_leitos(Leitos *leitos, Paciente *paciente, Log *log)
{
  if (leitos_cheio(leitos))
  {
    printf("Os leitos estão lotados!");
  }
  else
  {
    leitos->pacientes[leitos->tamanho] = paciente;
    leitos->tamanho++;
    adicionar_paciente_leito_log(log, paciente);
  }
}

//-----------------------------------

Paciente *remover_leitos(Leitos *leitos)
{
  if (leitos_vazio(leitos))
  {
    printf("Os leitos estão vazios!\n");
    Paciente *paciente_vazio = NULL;
    return paciente_vazio;
  }
  else
  {
    Paciente *paciente = copiar_paciente(leitos->pacientes[0]);

    liberar_paciente(leitos->pacientes[0]);

    for (int i = 1; i < leitos->tamanho; i++)
    {
      leitos->pacientes[i - 1] = leitos->pacientes[i];
    }
    leitos->tamanho--;
    return paciente;
  }
}

//-----------------------------------

Paciente *consultar_primeiro(Leitos *leitos)
{
  if (leitos_vazio(leitos))
  {
    printf("Os leitos estão vazios!\n");
    Paciente *paciente_vazio = NULL;
    return paciente_vazio;
  }
  else
  {
    return leitos->pacientes[0];
  }
}

//-----------------------------------

void exibir_leitos(Leitos *leitos)
{
  if (leitos_vazio(leitos))
  {
    printf("Os leitos estão vazios!\n");
  }
  else
  {
    printf("------ Leitos ------\n");
    for (int i = 0; i < leitos->tamanho; i++)
    {
      printf("Leito %d:", i + 1);
      Paciente *pacienteTemp = leitos->pacientes[i];
      exibir_paciente(pacienteTemp);
    }
    printf("\n");
  }
}

//-----------------------------------
