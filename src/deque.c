#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/deque.h"
#include "../include/paciente.h"
#include "../include/log.h"

void inicia_deque(Deque *d)
{
    d->inicio = NULL;
    d->final = NULL;
    d->tamanho = 0;
}

int inserir_deque(Deque *d, Paciente *paciente, Log *log)
{
    if (d->tamanho < TAMANHODEQUE) // Verifica se o deque está cheio
    {
        if (paciente->prioridade >= 4)
        { // Prioridade alta
            paciente->atendido += 1;

            insere_inicio(d, paciente);
            adicionar_paciente_espera_log(log, paciente);
            return 0;
        }
        else if (paciente->prioridade <= 3)
        { // Prioridade baixa
            paciente->atendido += 1;

            insere_final(d, paciente);
            adicionar_paciente_espera_log(log, paciente);

            return 0;
        }
    }
    else
    {
        return -1;
    }
}

Paciente *remover_deque(Deque *d)
{
    if (d->tamanho > 0)
    {
        if (d->inicio->paciente.prioridade > d->final->paciente.prioridade)
        {
            return remove_inicio(d);
        }
        else if (d->inicio->paciente.prioridade < d->final->paciente.prioridade)
        {
            return remove_final(d);
        }
        else
        {
            return remove_inicio(d);
        }
    }
    else
    {
        Paciente *paciente_vazio = NULL;
        printf("Deque vazio!\n");

        return paciente_vazio;
    }
}

void insere_inicio(Deque *d, Paciente *paciente)
{
    NoDeque *novo_no = (NoDeque *)malloc(sizeof(NoDeque));
    if (novo_no) // Verifica se conseguiu alocar memória
    {
        novo_no->paciente = *copiar_paciente(paciente);

        novo_no->proximo = d->inicio;
        novo_no->anterior = NULL;

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
    else
    {
        printf("Erro de alocação.\n");
    }
}

void insere_final(Deque *d, Paciente *paciente)
{
    NoDeque *novo_no = (NoDeque *)malloc(sizeof(NoDeque));
    if (novo_no)
    { // Verifica se conseguiu alocar memória
        novo_no->paciente = *copiar_paciente(paciente);
        novo_no->proximo = NULL;
        novo_no->anterior = d->final;

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
    else
    {
        printf("Erro de alocação.\n");
    }
}

Paciente *remove_inicio(Deque *d)
{
    if (d->inicio == NULL)
    {
        printf("Deque vazio!\n");
        Paciente *paciente_vazio = NULL;
        return paciente_vazio;
    }

    NoDeque *temp = d->inicio;

    Paciente *copiaPaciente = copiar_paciente(&temp->paciente); // fazemos uma cópia do paciente para retornar ele

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

Paciente *remove_final(Deque *d)
{
    if (d->final == NULL)
    {
        printf("Deque vazio!\n");
        Paciente *paciente_vazio = NULL;
        return paciente_vazio;
    }

    NoDeque *temp = d->final;

    Paciente *copiaPaciente = copiar_paciente(&temp->paciente); // fazemos uma cópia do paciente para retornar ele

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

void imprime_deque(Deque *d)
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
        printf("ID: %s, Nome: %s, Idade: %d, Sexo: %c, CPF: %s, Prioridade: %d, Atendido: %d\n\n",
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
