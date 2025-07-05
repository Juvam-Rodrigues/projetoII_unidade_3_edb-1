#include "../include/paciente.h"
#include <string.h>
#include <stdlib.h>

Paciente *copiar_paciente(Paciente *orig)
{
    Paciente *c = malloc(sizeof(Paciente));
    if (c == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return c;
    }

    c->ID = strdup(orig->ID);
    c->nome = strdup(orig->nome);
    c->cpf = strdup(orig->cpf);

    c->idade = orig->idade;
    c->sexo = orig->sexo;
    c->prioridade = orig->prioridade;
    c->atendido = orig->atendido;

    return c;
}
void liberar_paciente(Paciente *p)
{
    if (p)
    {
        free(p->ID);
        free(p->nome);
        free(p->cpf);
        free(p);
    }
}

void exibir_paciente(Paciente *paciente)
{
    printf("\n--------\n");
    printf("ID: %s, ", paciente->ID);
    printf("Nome: %s, ", paciente->nome);
    printf("Idade: %d, ", paciente->idade);
    printf("Sexo: %c, ", paciente->sexo);
    printf("CPF: %s, ", paciente->cpf);
    printf("Prioridade: %d, ", paciente->prioridade);
    printf("Atendido: %d.\n", paciente->atendido);
}