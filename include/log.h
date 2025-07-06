#ifndef LOG_H //Histórico Arquivo Log
#define LOG_H

#include "paciente.h"

typedef struct NoLog
{
  Paciente *paciente;
  struct NoLog *proximo;
} NoLog;

typedef struct Log{
    int qtdCiclos;
    NoLog *pacientesAlta; //Pilha
    NoLog *pacientesLeito; //Lista
    NoLog *pacienteEspera; //Deque

}Log;

void inicializar_log(Log *log);
int preencher_log(Log *log, char *nomeArquivo);
NoLog *criar_no_log(Paciente *paciente);
void adicionar_paciente_espera_log(Log *log, Paciente *paciente);
void adicionar_paciente_leito_log(Log *log, Paciente *paciente);
void adicionar_paciente_alta_log(Log *log, Paciente *paciente);

void imprimir_log(Log *log, FILE *arq);


#endif

