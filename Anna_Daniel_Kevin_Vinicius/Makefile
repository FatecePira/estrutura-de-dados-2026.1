# ============================================================
#  Makefile — Simulador de Estruturas de Dados Lineares em C
# ============================================================

CC      = gcc # Define a variavel CC indicando que o compilador oficial do projeto eh o GCC
CFLAGS  = -Wall -Wextra -std=c11 -I include # Flags: -Wall e -Wextra ativam avisos de erro; -std=c11 usa o padrao C11; -I include mapeia a pasta de cabecalhos
TARGET  = simulador # Define o nome do arquivo executavel final que sera gerado
SRCDIR  = src # Define a pasta onde estao os codigos fonte (.c)
SRCS    = main.c \
          $(SRCDIR)/comum.c \
          $(SRCDIR)/lista_seq.c \
          $(SRCDIR)/lista_enc.c \
          $(SRCDIR)/pilha.c \
          $(SRCDIR)/fila.c \
          $(SRCDIR)/fila_circ.c \
          $(SRCDIR)/fila_dupla.c \
          $(SRCDIR)/fila_prio.c # Lista todos os arquivos .c que compoem o projeto separados por quebra de linha (\)

all: $(TARGET) # Alvo principal (default). Indica que o comando 'make all' depende da criacao do TARGET (simulador)

$(TARGET): $(SRCS) # Regra de construcao: o executavel (TARGET) depende da lista de arquivos fonte (SRCS)
	$(CC) $(CFLAGS) -o $@ $^ # Comando de compilacao. $@ (Nome do Alvo) vira 'simulador'. $^ (Dependencias) vira a lista de arquivos .c
	@echo "Compilacao concluida! Execute com: ./$(TARGET)" # Imprime mensagem de sucesso no terminal ocultando o comando real (devido ao @)

clean: # Alvo utilitario para limpeza do projeto
	rm -f $(TARGET) # Apaga o executavel gerado anteriormente para forcar uma compilacao limpa

.PHONY: all clean # Declara que 'all' e 'clean' sao comandos (alvos falsos) e nao arquivos reais no disco