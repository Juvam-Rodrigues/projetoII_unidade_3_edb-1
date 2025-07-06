OBJS = exe/main.o exe/deque.o exe/leitos.o exe/paciente.o exe/pilha.o exe/tabela.o exe/log.o
INCLUDE = include/deque.h include/leitos.h include/log.h include/paciente.h include/pilha.h include/tabela.h
MAIN = src/main.c
DEQUE = src/deque.c
LEITOS = src/leitos.c
PACIENTE = src/paciente.c
LOG = src/log.c
PILHA = src/pilha.c
TABELA = src/tabela.c
PROG = exe/executavel.exe

$(PROG): $(OBJS)
	gcc -o $(PROG) $(OBJS)

exe/main.o: $(MAIN)
	gcc -c $(MAIN) -o exe/main.o

exe/deque.o: $(DEQUE)
	gcc -c $(DEQUE) -o exe/deque.o

exe/leitos.o: $(LEITOS)
	gcc -c $(LEITOS) -o exe/leitos.o

exe/log.o: $(LOG)
	gcc -c $(LOG) -o exe/log.o

exe/paciente.o: $(PACIENTE)
	gcc -c $(PACIENTE) -o exe/paciente.o

exe/pilha.o: $(PILHA)
	gcc -c $(PILHA) -o exe/pilha.o

exe/tabela.o: $(TABELA)
	gcc -c $(TABELA) -o exe/tabela.o

run: $(PROG)
	./$(PROG)

clean:
ifeq ($(OS),Windows_NT)
	cmd /c del /f /q $(subst /,\,$(OBJS)) $(subst /,\,$(PROG))
else
	rm -f $(OBJS) $(PROG)
endif

