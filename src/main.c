#include <stdio.h>
#include <time.h>
#include "../include/tabela.h"
#include "../include/paciente.h"
#include "../include/deque.h"
#include "../include/leitos.h"
#include "../include/pilha.h"
#include "../include/log.h"

int main()
{

    srand(time(NULL)); // Inicializa a semente, para mudar as sequências de números a cada execução
    // Se baseia no tempo atual em segundos do computador

    char *nomeArquivo;
    nomeArquivo = "data/pacientes.csv";

    Tabela tabela;
    Log log;
    inicializar_log(&log);

    if (preencher_pacientes(&tabela, nomeArquivo) == -1)
    {
        return -1;
    }

    Deque deque;
    inicia_deque(&deque);

    int numeroSorteado;

    for (int i = 0; i < 20; i++)
    {
        numeroSorteado = sortear_posicao(&tabela);

        Paciente *pacienteSorteado;
        pacienteSorteado = buscar_paciente_tabela(&tabela, numeroSorteado);

        //printf("Pessoa sorteada: %s, %s, atendido: %d\n", pacienteSorteado->ID, pacienteSorteado->nome, pacienteSorteado->atendido);

        int resultado = inserir_deque(&deque, pacienteSorteado, &log);
        if (resultado == 0)
        {
            //printf("Inseriu pessoa no deque. \n");
        }
        else
        {
            printf("Deque cheio \n");
        }
    }
    imprime_deque(&deque);

    Leitos leitos;
    inicializar_leitos(&leitos);

    Paciente *pacienteRemovido = remover_deque(&deque);
    
    printf("Pessoa removida do deque: %s, %s, prioridade: %d\n\n", pacienteRemovido->ID, pacienteRemovido->nome, pacienteRemovido->prioridade);
    //imprime_deque(&deque);
    
    inserir_leitos(&leitos, pacienteRemovido, &log);
    printf("Pessoa encaminhada para o leito: %s, %s, prioridade: %d\n\n", pacienteRemovido->ID, pacienteRemovido->nome, pacienteRemovido->prioridade);
    exibir_leitos(&leitos);
    
    Paciente *pacienteRemovidoLeito = remover_leitos(&leitos);
    printf("Pessoa teve alta: %s, %s, prioridade: %d\n\n", pacienteRemovidoLeito->ID, pacienteRemovidoLeito->nome, pacienteRemovidoLeito->prioridade);

    Pilha historico;
    historico.topo = -1; //Histórico inicialmente vazio
    push(&historico, pacienteRemovidoLeito, &log);
    Paciente *h1 = peek(&historico);
    printf("Histórico\n%s, %s\n\n", h1->ID, h1->nome);

    int resultado = preencher_log(&log, "data/log.log");
    if (resultado == -1)
    {
        return -1;
    }
    return 0;
}