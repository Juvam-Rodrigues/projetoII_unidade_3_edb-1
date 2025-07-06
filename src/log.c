#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/paciente.h"
#include "../include/log.h"

void inicializar_log(Log *log)
{
    log->qtdCiclos = 0;
    log->pacientesAlta = NULL;
    log->pacientesLeito = NULL;
    log->pacienteEspera = NULL;
}

NoLog *criar_no_log(Paciente *paciente)
{
    NoLog *novo_no = (NoLog *)malloc(sizeof(NoLog));
    if (novo_no) // Verifica se conseguiu alocar memória
    {
        novo_no->paciente = copiar_paciente(paciente);
        novo_no->proximo = NULL;
    }
    return novo_no;
}

int preencher_log(Log *log, char *nomeArquivo)
{
    FILE *arq = fopen(nomeArquivo, "a+"); // Modo para escrita usando append e leitura

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return -1;
    }

    log->qtdCiclos += 1;
    fprintf(arq, "[CICLO %d]\n", log->qtdCiclos);

    imprimir_log(log, arq);
    
    fclose(arq);
    return 0;
}

void adicionar_paciente_espera_log(Log *log, Paciente *paciente)
{
    NoLog *novo_no = criar_no_log(paciente);

    if (novo_no != NULL)
    {
        if (log->pacienteEspera == NULL)
        {
            log->pacienteEspera = novo_no;
        }
        else
        {
            novo_no->proximo = log->pacienteEspera;
            log->pacienteEspera = novo_no;
        }
    }
}

void adicionar_paciente_leito_log(Log *log, Paciente *paciente)
{
    NoLog *novo_no = criar_no_log(paciente);

    if (novo_no != NULL)
    {
        if (log->pacientesLeito == NULL)
        {
            log->pacientesLeito = novo_no;
        }
        else
        {
            novo_no->proximo = log->pacientesLeito;
            log->pacientesLeito = novo_no;
        }
    }
}

void adicionar_paciente_alta_log(Log *log, Paciente *paciente)
{
    NoLog *novo_no = criar_no_log(paciente);

    if (novo_no != NULL)
    {
        if (log->pacientesAlta == NULL)
        {
            log->pacientesAlta = novo_no;
        }
        else
        {
            novo_no->proximo = log->pacientesAlta;
            log->pacientesAlta = novo_no;
        }
    }
}

void limpar_listas(Log *log)
{
    NoLog *atual = log->pacienteEspera;
    while (atual != NULL)
    {
        NoLog *prox = atual->proximo;
        liberar_paciente(atual->paciente); // Libera a memória alocada para cada campo de paciente, além do ponteiro para paciente
        free(atual);                       // Libera a memória alocada para o nó

        atual = prox;
    }
    log->pacienteEspera = NULL;

    atual = log->pacientesLeito;

    while (atual != NULL)
    {
        NoLog *prox = atual->proximo;
        liberar_paciente(atual->paciente); // Libera a memória alocada para cada campo de paciente, além do ponteiro para paciente
        free(atual);                       // Libera a memória alocada para o nó

        atual = prox;
    }
    log->pacientesLeito = NULL;

    atual = log->pacientesAlta;
    while (atual != NULL)
    {
        NoLog *prox = atual->proximo;
        liberar_paciente(atual->paciente); // Libera a memória alocada para cada campo de paciente, além do ponteiro para paciente
        free(atual);                       // Libera a memória alocada para o nó

        atual = prox;
    }
    log->pacientesAlta = NULL;
}

void imprimir_log(Log *log, FILE *arq)
{
    NoLog *aux = log->pacientesAlta;
    while (aux != NULL)
    {

        fprintf(arq,"ALTA   -   %s  (%s)\n", aux->paciente->ID, aux->paciente->nome);
        aux = aux->proximo;
    }

    aux = log->pacientesLeito;
    while (aux != NULL)
    {

        fprintf(arq,"INTERNADO   -   %s  (%s)\n", aux->paciente->ID, aux->paciente->nome);
        aux = aux->proximo;
    }

    aux = log->pacienteEspera;
    while (aux != NULL)
    {

        fprintf(arq,"ESPERA   -   %s  (%s)\n", aux->paciente->ID, aux->paciente->nome);
        aux = aux->proximo;
    }
}