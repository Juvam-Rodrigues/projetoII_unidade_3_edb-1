#include "../include/paciente.h"

Paciente copiar_paciente(Paciente *orig)
{
    Paciente c;
    c.ID = malloc(strlen(orig->ID) + 1);
    strcpy(c.ID, orig->ID);

    c.nome = malloc(strlen(orig->nome) + 1);
    strcpy(c.nome, orig->nome);

    c.idade = orig->idade;
    c.sexo = orig->sexo;

    c.cpf = malloc(strlen(orig->cpf) + 1);
    strcpy(c.cpf, orig->cpf);

    c.prioridade = orig->prioridade;
    c.atendido = orig->atendido;

    return c;
}