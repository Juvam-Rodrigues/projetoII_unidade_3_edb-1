#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/paciente.h"
#include "../include/tabela.h"

void inicializar_tabela(Tabela *tabela)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        tabela->tabela[i] = NULL;
    }
}

int funcao_hash(int chave)
{
    return chave % TAMANHO;
}

No *criar_no(Paciente paciente)
{
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no)
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

        novo_no->proximo = NULL;
    }
    return novo_no;
}

void inserir(Tabela *tabela, Paciente paciente, int chave)
{
    int indice = funcao_hash(chave);
    No *novo_no = criar_no(paciente);

    if (tabela->tabela[indice] == NULL)
    {
        tabela->tabela[indice] = novo_no;
    }
    else
    {
        novo_no->proximo = tabela->tabela[indice];
        tabela->tabela[indice] = novo_no;
    }
}

void imprimir_tabela(Tabela *tabela)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Índice %d: ", i);
        No *atual = tabela->tabela[i];
        while (atual != NULL)
        {
            printf("ID: %s\n", atual->paciente.ID);
            printf("Nome: %s\n", atual->paciente.nome);
            printf("Idade: %d\n", atual->paciente.idade);
            printf("Sexo: %c\n", atual->paciente.sexo);
            printf("CPF: %s\n", atual->paciente.cpf);
            printf("Prioridade: %d\n", atual->paciente.prioridade);
            printf("Atendido: %d\n", atual->paciente.atendido);
            printf("--------\n");
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

int main()
{
    FILE *arq = fopen("../data/pacientes.csv", "r"); // Modo de leitura

    if (arq == NULL)
    {
        printf("Arquivo não existe!");
        return 1;
    }

    Tabela tabel;
    inicializar_tabela(&tabel);

    char linha[5000]; // Máx. de caracteres por linha

    fgets(linha, sizeof(linha), arq); // Pula a primeira linha

    // Ler cada linha do arquivo
    while (fgets(linha, sizeof(linha), arq))
    {
        linha[strcspn(linha, "\n")] = 0; // Remove '\n'

        Paciente p;

        // Separar os campos por ';'
        char *campo = strtok(linha, ";");

        if (campo != NULL)
        {
            p.ID = malloc(strlen(campo) + 1);
            strcpy(p.ID, campo);
        }

        campo = strtok(NULL, ";");

        if (campo != NULL)
        {
            p.nome = malloc(strlen(campo) + 1);
            strcpy(p.nome, campo);
        }

        campo = strtok(NULL, ";");

        if (campo != NULL)
        {
            p.idade = atoi(campo);
        }

        campo = strtok(NULL, ";");

        if (campo != NULL)
        {
            p.sexo = campo[0]; // Só 1 char
        }

        campo = strtok(NULL, ";");

        if (campo != NULL)
        {
            p.cpf = malloc(strlen(campo) + 1);
            strcpy(p.cpf, campo);
        }

        campo = strtok(NULL, ";");

        if (campo != NULL)
        {
            p.prioridade = atoi(campo);
        }

        campo = strtok(NULL, ";");
        if (campo != NULL)
        {
            p.atendido = atoi(campo);
        }

        inserir(&tabel, p, atoi(p.cpf));

        free(p.ID);
        free(p.nome);
        free(p.cpf);
    }
    imprimir_tabela(&tabel);
    fclose(arq);
    return 0;
}