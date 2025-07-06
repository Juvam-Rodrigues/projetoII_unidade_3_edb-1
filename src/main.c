#include <stdio.h>
#include <time.h>
#include <unistd.h>
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
    Pilha historico;
    Leitos leitos;
    Deque deque;

    inicializar_leitos(&leitos);
    historico.topo = -1;
    inicializar_log(&log);
    inicia_deque(&deque);

    if (preencher_pacientes(&tabela, nomeArquivo) == -1)
    {
        return -1;
    }


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

    while (!esta_cheia(&historico))
    {
        int posicao_sorteada = sortear_posicao(&tabela);
        Paciente *paciente_sorteado = buscar_paciente_tabela(&tabela, posicao_sorteada);

        if(paciente_sorteado != NULL) {
            printf("Paciente sorteado para a fila de espera:\n");
            exibir_paciente(paciente_sorteado);
            inserir_deque(&deque, paciente_sorteado, &log);
        }

        if (paciente_sorteado == NULL) {
            printf("Todos os pacientes já foram atendidos!\n");
        }

        Paciente *pacienteRemovido = remover_deque(&deque);

        if (pacienteRemovido != NULL) {
            inserir_leitos(&leitos, pacienteRemovido, &log);
            printf("\n--------\n");
            printf("Paciente encaminhado para o leito: %s, %s, prioridade: %d\n\n", pacienteRemovido->ID, pacienteRemovido->nome, pacienteRemovido->prioridade);
            exibir_leitos(&leitos);

            int validacao_alta = rand();
            Paciente *pacienteRemovidoLeito;

            if (validacao_alta % pacienteRemovido->prioridade == 0)
            { // Validação aleatoria se paciente terá alta ou nao, se o numero aleatorio gerado for divisivel pelo valor da prioridade do paciente, ele terá alta
                pacienteRemovidoLeito = remover_leitos(&leitos);
                printf("Paciente teve alta: %s, %s, prioridade: %d\n\n", pacienteRemovidoLeito->ID, pacienteRemovidoLeito->nome, pacienteRemovidoLeito->prioridade);
                push(&historico, pacienteRemovidoLeito, &log);
                Paciente *h1 = peek(&historico);
                printf("Histórico\n%s, %s\n\n", h1->ID, h1->nome);
            } else {
            printf("Paciente %s ainda permanecerá no leito.", pacienteRemovido->nome);
        }

        if (pacienteRemovido == NULL) {
            printf("Todos os pacientes da fila de espera já foram encaminhados!\n");
        }

    }


    int resultado = preencher_log(&log, "data/log.log");
    if (resultado == -1)
    {
        return -1;
    }
    }
        
    return 0;
}