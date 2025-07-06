#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/paciente.h"
#include "../include/tabela.h"

void inicializar_tabela(Tabela *tabela)
{
    tabela->tamanho = 50;
    for (int i = 0; i < tabela->tamanho; i++)
    {
        tabela->tabela[i] = NULL;
    }
}

int funcao_hash(int chave)
{
    return chave % TAMANHOTABELA;
}

NoTabela *criar_no(Paciente paciente)
{
    NoTabela *novo_no = (NoTabela *)malloc(sizeof(NoTabela));
    if (novo_no) // Verifica se conseguiu alocar memória
    {
        novo_no->paciente = copiar_paciente(&paciente);
        novo_no->proximo = NULL;
    }
    return novo_no;
}

void inserir_tabela(Tabela *tabela, Paciente paciente, int chave)
{
    int indice = funcao_hash(chave);
    NoTabela *novo_no = criar_no(paciente);

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
    for (int i = 0; i < tabela->tamanho; i++)
    {
        printf("\nÍndice %d: ", i);
        NoTabela *atual = tabela->tabela[i];
        while (atual != NULL)
        {
            Paciente *pacienteTemp = atual->paciente;
            exibir_paciente(pacienteTemp);
            atual = atual->proximo;
        }
        printf("Nó cauda = NULL\n");
    }
}

int preencher_pacientes(Tabela *tabel, char *nomeArquivo)
{
    FILE *arq = fopen(nomeArquivo, "r"); // Modo de leitura

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo '%s'.", nomeArquivo);
        return -1;
    }

    inicializar_tabela(tabel);

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

        char *chave = malloc(strlen(p.ID) - 2); //-3 dá parte do PAC + 1 do /0 = 2
        strcpy(chave, p.ID + 3);                // Copia do índice 3 para frente

        inserir_tabela(tabel, p, atoi(chave));

        // free(chave);
        // free(p.ID);
        // free(p.nome);
        // free(p.cpf);
    }
    // imprimir_tabela(tabel);
    fclose(arq);
    return 0;
}

int sortear_posicao(Tabela *tabel)
{
    int numero = rand() % tabel->tamanho;
    return numero;
}

int todos_pacientes_atendidos(Tabela *tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        NoTabela *atual = tabela->tabela[i]; 

        while (atual != NULL) {
            if (atual->paciente != NULL && atual->paciente->atendido == 0) {
                return 0; 
            }
            atual = atual->proximo; 
        }
    }

    return 1;
}

Paciente* buscar_paciente_tabela(Tabela *tabela, int numeroSorteado)
{
    NoTabela *atual = tabela->tabela[numeroSorteado];

    if(todos_pacientes_atendidos(tabela) == 1) {
        printf("Todos os pacientes já foram atendidos!\n");
        return NULL;
    }

    while (atual != NULL)
    {
        if (atual->paciente->atendido == 0)
        {
            return atual->paciente;
        }
        atual = atual->proximo;
    }

    // Não achou alguém sem ser atendido, vai sorteando até sair
    int novoNumeroSorteado = sortear_posicao(tabela);

    return buscar_paciente_tabela(tabela, novoNumeroSorteado);
}
