# Checklist de requisitos atendidos

Baseado no enunciado do trabalho, o projeto atende aos seguintes pontos:

- Codigo em linguagem C.
- Menu principal com as 7 estruturas obrigatorias.
- Submenus especificos por estrutura.
- Funcoes separadas para cada operacao.
- Organizacao em arquivos `.h` e `.c`.
- Limite de 100 elementos por estrutura.
- Estruturas independentes entre si.
- Validacao de estrutura vazia antes de remocoes e consultas.
- Validacao de estrutura cheia nas estruturas com limite de 100 elementos.
- Lista sequencial com vetor.
- Lista simplesmente encadeada com ponteiros e alocacao dinamica.
- Pilha com regra LIFO.
- Fila com regra FIFO.
- Fila circular com controle de `inicio` e `fim`.
- Fila dupla com insercao e remocao nos dois extremos.
- Fila de prioridade com remocao do elemento de maior prioridade.

## Arquivos principais

- `main.c`: menu principal e submenus.
- `elemento.h`: estrutura padrao dos elementos.
- `utils.c/.h`: leitura segura e exibicao de elementos.
- `lista_sequencial.c/.h`: lista sequencial.
- `lista_encadeada.c/.h`: lista simplesmente encadeada.
- `pilha.c/.h`: pilha.
- `fila.c/.h`: fila comum.
- `fila_circular.c/.h`: fila circular.
- `fila_dupla.c/.h`: fila dupla.
- `fila_prioridade.c/.h`: fila de prioridade.

## Teste automatico simples

Compile:

```bash
gcc -Wall -Wextra -std=c99 -pedantic main.c utils.c lista_sequencial.c lista_encadeada.c pilha.c fila.c fila_circular.c fila_dupla.c fila_prioridade.c -o simulador
```

Execute o teste:

```bash
./simulador < entrada_teste.txt > minha_saida.txt
```

Compare com `saida_teste.txt` ou leia a saida para verificar as operacoes demonstradas.
