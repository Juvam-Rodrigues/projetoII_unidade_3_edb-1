#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/deque.h"
#include "../include/paciente.h"

void inicia_deque(Deque *d)
{
    d->inicio = NULL;
    d->final = NULL;
    d->tamanho = 0;
}

void insere_inicio(Deque *d, Paciente paciente)
{
    NoDeque *novo_no = (NoDeque *)malloc(sizeof(NoDeque));
    if (novo_no) // Verifica se conseguiu alocar memória
    {
        novo_no->paciente.ID = malloc(strlen(paciente.ID) + 1);
        strcpy(novo_no->paciente.ID, paciente.ID);

        novo_no->paciente.nome = malloc(strlen(paciente.nome) + 1);
        strcpy(novo_no->paciente.nome, paciente.nome);

        novo_no->paciente.idade = paciente.idade;
        novo_no->paciente.sexo = paciente.sexo;

        novo_no->paciente.cpf = malloc(strlen(paciente.cpf) + 1);
        strcpy(novo_no->paciente.cpf, paciente.cpf);

        novo_no->paciente.prioridade = paciente.prioridade;
        novo_no->paciente.atendido = paciente.atendido;

        novo_no->proximo = d->inicio;
        novo_no->anterior = NULL;
    }

    if (d->inicio != NULL)
    {
        d->inicio->anterior = novo_no;
    }

    d->inicio = novo_no;

    if (d->final == NULL)
    {
        d->final = novo_no;
    }

    d->tamanho++;
}

void insere_final(Deque *d, Paciente paciente)
{
    NoDeque *novo_no = (NoDeque *)malloc(sizeof(NoDeque));
    if (novo_no)
    { // Verifica se conseguiu alocar memória
        novo_no->paciente.ID = malloc(strlen(paciente.ID) + 1);
        strcpy(novo_no->paciente.ID, paciente.ID);

        novo_no->paciente.nome = malloc(strlen(paciente.nome) + 1);
        strcpy(novo_no->paciente.nome, paciente.nome);

        novo_no->paciente.idade = paciente.idade;
        novo_no->paciente.sexo = paciente.sexo;

        novo_no->paciente.cpf = malloc(strlen(paciente.cpf) + 1);
        strcpy(novo_no->paciente.cpf, paciente.cpf);

        novo_no->paciente.prioridade = paciente.prioridade;
        novo_no->paciente.atendido = paciente.atendido;

        novo_no->proximo = NULL;
        novo_no->anterior = d->final;
    }

    if (d->final != NULL)
    {
        d->final->proximo = novo_no;
    }

    d->final = novo_no;

    if (d->inicio == NULL)
    {
        d->inicio = novo_no;
    }

    d->tamanho++;
}

Paciente remove_inicio(Deque *d)
{
    if (d->inicio == NULL)
    {
        printf("Deque vazio!\n");
        Paciente paciente_vazio = {0};
        return paciente_vazio;
    }

    NoDeque *temp = d->inicio;

    Paciente copiaPaciente = copiar_paciente(&temp->paciente); // fazemos uma cópia do paciente para retornar ele

    d->inicio = d->inicio->proximo;

    if (d->inicio == NULL)
    {
        d->final = NULL;
    }
    else
    {
        d->inicio->anterior = NULL;
    }

    free(temp->paciente.ID);
    free(temp->paciente.nome);
    free(temp->paciente.cpf);
    free(temp);

    d->tamanho--;

    return copiaPaciente;
}

Paciente remove_final(Deque *d)
{
    if (d->final == NULL)
    {
        printf("Deque vazio!\n");
        Paciente paciente_vazio = {0};
        return paciente_vazio;
    }

    NoDeque *temp = d->final;

    Paciente copiaPaciente = copiar_paciente(&temp->paciente); // fazemos uma cópia do paciente para retornar ele

    d->final = d->final->anterior;

    if (d->final == NULL)
    {
        d->inicio = NULL;
    }
    else
    {
        d->final->proximo = NULL;
    }

    free(temp->paciente.ID);
    free(temp->paciente.nome);
    free(temp->paciente.cpf);
    free(temp);

    d->tamanho--;

    return copiaPaciente;
}

Paciente pega_inicio(Deque *d)
{
    if (d->inicio == NULL)
    {
        printf("Deque vazio!\n");
        Paciente paciente_vazio = {0};
        return paciente_vazio;
    }

    return d->inicio->paciente;
}

Paciente pega_final(Deque *d)
{
    if (d->final == NULL)
    {
        printf("Deque vazio!\n");
        Paciente paciente_vazio = {0};
        return paciente_vazio;
    }

    return d->final->paciente;
}

int esta_vazio(Deque *d)
{
    return d->tamanho == 0;
}

void imprime(Deque *d)
{
    if (esta_vazio(d))
    {
        printf("Deque vazio!\n");
        return;
    }

    NoDeque *aux = d->inicio;

    printf("Deque: ");
    while (aux != NULL)
    {
        printf("ID: %s, Nome: %s, Idade: %d, Sexo: %c, CPF: %s, Prioridade: %d, Atendido: %d\n",
               aux->paciente.ID,
               aux->paciente.nome,
               aux->paciente.idade,
               aux->paciente.sexo,
               aux->paciente.cpf,
               aux->paciente.prioridade,
               aux->paciente.atendido);
        aux = aux->proximo;
    }

    printf("\n");
}
