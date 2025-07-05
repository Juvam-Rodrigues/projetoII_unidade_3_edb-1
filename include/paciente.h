#ifndef PACIENTE_H
#define PACIENTE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Paciente
{
    char *ID;
    char *nome;
    char *cpf;
    int idade;
    int prioridade;
    int atendido;
    char sexo;

} Paciente;

Paciente copiar_paciente(Paciente *orig);
void exibir_paciente(Paciente *paciente);

#endif
