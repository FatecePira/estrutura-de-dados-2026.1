CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
TARGET = simulador
OBJS = main.o utils.o lista_sequencial.o lista_encadeada.o pilha.o fila.o fila_circular.o fila_dupla.o fila_prioridade.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
