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

    char *nomeArquivoCSV = "data/pacientes.csv";
    char *nomeArquivoLog = "data/processamento.log";

    limpar_arquivo_log(nomeArquivoLog);

    Tabela tabela;
    Log log;
    Pilha historico;
    Leitos leitos;
    Deque deque;

    inicializar_leitos(&leitos);
    historico.topo = -1;
    inicializar_log(&log);

    inicia_deque(&deque);
    if (preencher_pacientes(&tabela, nomeArquivoCSV) == -1)
    {
        return -1;
    }


    

    while (!esta_cheia(&historico))
    {
        printf("\n------------------------------------ NOVO CICLO [%d]------------------------------------\n", log.qtdCiclos);
        printf("\nPacientes na fila de espera: %d  |  Pacientes nos leitos: %d  |  Pacientes com alta: %d\n", deque.tamanho, leitos.tamanho, historico.topo + 1);
        printf("\n");

        limpar_listas(&log); 

         //ETAPA 1 - Verificar se a condição é atendida para dar alta a paciente e inserir no histórico

         if(!leitos_vazio(&leitos)) {
            Paciente *primeiro_leito = consultar_primeiro(&leitos);

            int validacao_alta = rand();

            if (primeiro_leito != NULL && validacao_alta % 2 == 0 ) {
                Paciente *pacienteDeAlta = remover_leitos(&leitos);
                printf("ALTA CONCEDIDA para o paciente %s %s.\n", pacienteDeAlta->ID, pacienteDeAlta->nome);
                push(&historico, pacienteDeAlta, &log);
            } 
        } 

        //FIM DA ETAPA 1

        //ETAPA 2 - Checar se há leitos disponíveis e internar paciente da fila de espera

        if(!leitos_cheio(&leitos) && !deque_vazio(&deque)) {
            Paciente *pacienteParaInternar = remover_deque(&deque);

            if(pacienteParaInternar != NULL) {
                inserir_leitos(&leitos, pacienteParaInternar, &log);
                printf("\n----- INTERNAÇÃO -----\n");
                printf("\nPaciente %s %s foi internado.\n", pacienteParaInternar->ID, pacienteParaInternar->nome);
            }
        }

        printf("\n----- OCUPAÇÃO DOS LEITOS -----\n");
        exibir_leitos(&leitos);
        printf("\n--------------------------------\n");    
        
        //FIM DA ETAPA 2

        //ETAPA 3 - Sortear pacientes e preencher a fila de espera 

        while(!deque_cheio(&deque)) {
            int numeroSorteado;
            numeroSorteado = sortear_posicao(&tabela);
    
            Paciente *pacienteSorteado;
            pacienteSorteado = buscar_paciente_tabela(&tabela, numeroSorteado);
    
            if(pacienteSorteado != NULL) {
                inserir_deque(&deque, pacienteSorteado, &log);
                printf("Paciente %s %s foi sorteado(a) para a fila de espera.\n", pacienteSorteado->ID, pacienteSorteado->nome);
            } else {
                printf("Não há mais pacientes para adicionar à fila.\n");
                break;
            }
        }
    
        printf("\n----- FILA DE ESPERA ATUAL -----\n");
        imprime_deque(&deque);
        printf("\n--------------------------------\n");    

        //FIM DA ETAPA 3


        //ETAPA 4 - Inserir os dados do ciclo no arquivo .log

        int resultado = preencher_log(&log, "data/processamento.log");
        if (resultado == -1)
        {
            return -1;
        }

        //FIM DA ETAPA 4

        //ETAPA 5 - Verificação adicional se o programa deve encerrar com base nas condições e delay de 2 segundos entre cada ciclo

        if (todos_pacientes_atendidos(&tabela) && deque_vazio(&deque) && leitos_vazio(&leitos)) {
            printf("\n ----- Todos os pacientes foram atendidos e tiveram alta.-----\n");
            printf("Total de pacientes com alta: %d\n", historico.topo + 1);
            printf("\nEncerrando programa.....\n");
            break;
        }

        sleep(2);
   
        //FIM DA ETAPA 5 
    }
    
    printf("\n\n--- PROGRAMA FINALIZADO ---\n");

    //LIBERANDO AS ESTRUTURAS QUE ARMAZENAM OS PONTEIROS FINAIS:
    limpar_listas(&log);
    liberar_tabela(&tabela);
    liberar_pilha(&historico);

    return 0;
}