#include <stdio.h>
#include "../include/tabela.h"
#include "../include/paciente.h"

int main(int argc, char *argv[])
{
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

}