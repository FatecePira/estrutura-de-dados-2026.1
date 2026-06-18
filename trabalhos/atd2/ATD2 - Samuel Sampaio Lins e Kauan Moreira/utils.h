#ifndef UTILS_H
#define UTILS_H

#include "elemento.h"

void limpar_buffer_entrada(void);
int ler_inteiro(const char *mensagem);
void ler_texto(const char *mensagem, char *destino, int tamanho);
Elemento ler_elemento_basico(void);
Elemento ler_elemento_com_prioridade(void);
void imprimir_elemento(Elemento elemento);
void pausar(void);

#endif
