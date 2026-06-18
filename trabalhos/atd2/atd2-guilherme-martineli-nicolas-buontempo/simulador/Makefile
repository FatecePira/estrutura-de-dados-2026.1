CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = simulador
SRCS = main.c tipos.c lista_sequencial.c lista_encadeada.c pilha.c fila.c fila_circular.c fila_dupla.c fila_prioridade.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
