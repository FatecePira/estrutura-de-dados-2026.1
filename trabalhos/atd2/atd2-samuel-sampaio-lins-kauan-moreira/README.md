# Simulador de Estruturas de Dados Lineares em C

Este projeto implementa um simulador em linguagem C para as principais estruturas de dados lineares solicitadas no trabalho prático:

1. Lista sequencial simples com vetor
2. Lista simplesmente encadeada
3. Pilha
4. Fila
5. Fila circular
6. Fila dupla
7. Fila de prioridade

## Como compilar

No terminal, dentro da pasta do projeto, execute:

```bash
gcc -Wall -Wextra -std=c99 -pedantic -o simulador main.c utils.c lista_sequencial.c lista_encadeada.c pilha.c fila.c fila_circular.c fila_dupla.c fila_prioridade.c
```

## Como executar

```bash
./simulador
```

## Organizacao

- `main.c`: menu principal e submenus.
- `elemento.h`: definicao do tipo `Elemento`.
- `utils.c/.h`: funcoes auxiliares para leitura e exibicao.
- Arquivos `.c/.h` de cada estrutura: operacoes especificas de insercao, remocao, consulta, exibicao e verificacoes.

## Observacoes

- Cada estrutura mantem seus proprios dados.
- O limite maximo e de 100 elementos por estrutura.
- As estruturas baseadas em vetor validam situacao cheia.
- Todas as estruturas validam situacao vazia antes de remocoes e consultas.
- A lista simplesmente encadeada usa ponteiros e alocacao dinamica.
- A fila circular e a fila dupla controlam indices com aritmetica modular.
- A fila de prioridade mantem os elementos ordenados da maior para a menor prioridade.
