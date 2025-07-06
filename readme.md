<h1>Sistema de Gerenciamento Hospitalar 🏥</h1>

<h2>Descrição 🤔</h2>
Este projeto implementa um sistema básico de gerenciamento hospitalar em C, simulando o atendimento de pacientes em um hospital. Ele gerencia:

<ul>
    <li>Lista de pacientes cadastrados;</li>
    <li>Fila de espera (deque);</li>
    <li>Leitos disponíveis para internação;</li>
    <li>Histórico de pacientes com alta (pilha); e</li>
    <li>Registro de logs de operações em arquivo.</li>
</ul>

O sistema simula ciclos de atendimento, onde pacientes são sorteados, internados, recebem alta e suas informações são gravadas em arquivo de log.

<h2>Funcionalidades principais 🤔</h2>

Leitura e armazenamento dos pacientes a partir de um arquivo CSV.
Fila de espera implementada como deque (fila dupla) para gerenciamento eficiente.
Internação de pacientes em leitos disponíveis.
Alta médica concedida aleatoriamente a pacientes internados.
Histórico de pacientes com alta armazenado em pilha.
Registro detalhado de ciclos de atendimento em arquivo de log.
Verificação automática para encerrar o programa quando todos os pacientes forem atendidos.

<h2>Estruturas e conceitos utilizados 🧑‍💻</h2>

<ul>
    <li><strong>Tabela Hash:</strong> Armazena os pacientes para busca rápida e aleatória;</li>
    <li><strong>Deque (Fila Dupla):</strong> Gerencia pacientes na fila de espera;</li>
    <li><strong>Leitos:</strong> Vetor com limite máximo para internar pacientes;</li>
    <li><strong>Pilha:</strong> Histórico de pacientes com alta; e</li>
    <li><strong>Logs:</strong> Listas encadeadas para registrar pacientes em diferentes estados (espera, internados, alta) e gravação em arquivo.</li>
</ul>

<h2>Estrutura de pastas: 📂</h1>
   <ul>
        <li>data
            <ul>
                <li>pacientes.csv</li>
                <li>processamento.log</li>
            </ul>
        </li>
        <li>exe
            <ul>
                <li>arquivos_objetos.o</li>
                <li>executavel.exe</li>
            </ul>
        </li>
        <li>include
            <ul>
                <li>deque.h</li>
                <li>leitos.h</li>
                <li>log.h</li>
                <li>paciente.h</li>
                <li>pilha.h</li>
                <li>tabela.h</li>
            </ul>
        </li>
        <li>src
            <ul>
                <li>deque.c</li>
                <li>leitos.c</li>
                <li>log.c</li>
                <li>main.c</li>
                <li>paciente.c</li>
                <li>pilha.c</li>
                <li>tabela.c</li>
            </ul>
        </li>
        <li>makefile</li>
        <li>readme.md</li>    
    </ul>

<h2>Colaboradores: 🤝</h2>
Este projeto possui por colaboradores (principais desenvolvedores):
<ul>
    <li>Juvam Rodrigues do Nascimento Neto (https://github.com/Juvam-Rodrigues); e</li>
    <li>Jadilson Igor de Campos Lopes (https://github.com/Jahomme).</li>
</ul>