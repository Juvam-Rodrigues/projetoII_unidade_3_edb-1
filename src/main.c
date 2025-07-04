#include <stdio.h>
#include <time.h>
#include "../include/tabela.h"
#include "../include/paciente.h"
#include "../include/deque.h"

int main(int argc, char *argv[])
{

    srand(time(NULL)); // Inicializa a semente, para mudar as sequências de números a cada execução
    // Se baseia no tempo atual em segundos do computador

    if (argc < 2)
    {
        printf("Erro! Quantidade de argumentos insuficiente!");
        return 1;
    }
    char *nomeArquivo;
    nomeArquivo = argv[1];

    Tabela tabela;
    if (preencherPacientes(&tabela, nomeArquivo) == -1)
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

        printf("Pessoa sorteada: %s, %s, atendido: %d\n", pacienteSorteado->ID, pacienteSorteado->nome, pacienteSorteado->atendido);

        int resultado = inserir_deque(&deque, pacienteSorteado);
        if (resultado == 0)
        {
            printf("Inseriu pessoa no deque. \n");
        }
        else
        {
            printf("Deque cheio \n");
        }
        printf("Pessoa sorteada: %s, %s, atendido: %d\n\n", pacienteSorteado->ID, pacienteSorteado->nome, pacienteSorteado->atendido);
    }

}