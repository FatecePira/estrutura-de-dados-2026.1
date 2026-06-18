# Compilador
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -I./biblioteca

# Executável final
TARGET = programa

# Arquivos fonte
SRC = Main.c \
      biblioteca/fila.c \
      biblioteca/filaCircular.c \
      biblioteca/filaDePrioridade.c \
      biblioteca/filaDupla.c \
      biblioteca/listaSequencial.c \
      biblioteca/listaSimplesEncadeada.c \
      biblioteca/pilha.c

# Objetos gerados
OBJ = $(SRC:.c=.o)

# Regra padrão
all: $(TARGET)

# Linkagem
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Executar
run: $(TARGET)
	./$(TARGET)

# Limpar arquivos compilados
clean:
	rm -f $(OBJ) $(TARGET)

# Recompilar tudo
rebuild: clean all