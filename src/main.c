#include <stdio.h>
#include <time.h>
#include "../include/tabela.h"
#include "../include/paciente.h"
#include "../include/deque.h"

int main(int argc, char *argv[])
{
    
    srand(time(NULL)); // Inicializa a semente, para mudar as sequências de números a cada execução
    //Se baseia no tempo atual do computador

    if (argc < 2)
    {
        printf("Erro! Quantidade de argumentos insuficiente!");
        return 1;
    }
    char *nomeArquivo; 
    nomeArquivo = argv[1];

    Tabela tabela;
    if(preencherPacientes(&tabela, nomeArquivo) == -1){
        return -1;
    }

    Deque deque;
    inicia_deque(&deque);
    int numeroSorteado;
    numeroSorteado = sortear_posicao(&tabela);
    

}