#ifndef LEITOS_H //Leitos
#define LEITOS_H


#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "log.h"


#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 10

typedef struct Leitos{
    Paciente *pacientes[TAMANHO_MAX];
    int tamanho;
} Leitos;

void inicializar_leitos(Leitos *leitos);
int leitos_vazio(Leitos *leitos);
int leitos_cheio(Leitos *leitos);
void inserir_leitos(Leitos *leitos, Paciente *paciente, Log *log);
Paciente* remover_leitos(Leitos *leitos);
Paciente* consultar_primeiro(Leitos *leitos);
void exibir_leitos(Leitos *leitos);

#endif