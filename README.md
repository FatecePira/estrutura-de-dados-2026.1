# Simulador de Estruturas de Dados Lineares em C

Trabalho prático da disciplina de Estrutura de Dados (FATECE).

## Integrantes e Divisão de Tarefas
* Anna Luiza Maneo da Silva: Responsável pela implementação das Listas (Sequencial e Simplesmente Encadeada).
* Daniel Moreira: Responsável pela codificação da Pilha (LIFO) e Fila (FIFO), gerenciamento do versionamento no GitHub e resolução de problemas de compilação em ambiente Windows.
* Kevin Viturino: Responsável pelas estruturas de lógica circular (Fila Circular e Fila Dupla/Deque).
* Vinicius de Souza: Responsável pela Fila de Prioridade, menus interativos e arquitetura principal do sistema (`main.c`).

## Descrição do Projeto
O projeto consiste em um simulador desenvolvido em linguagem C para demonstrar o funcionamento das principais estruturas de dados lineares. Cada estrutura possui seu próprio armazenamento, permitindo operações independentes de inserção, remoção, consulta e visualização dos dados.

## Estruturas Implementadas
* Lista Sequencial
* Lista Simplesmente Encadeada
* Pilha (LIFO)
* Fila (FIFO)
* Fila Circular
* Fila Dupla (Deque)
* Fila de Prioridade

## Principais Funcionalidades
* Inserção de elementos
* Remoção de elementos
* Consulta e exibição de dados
* Controle de capacidade máxima
* Validação de operações inválidas
* Menus interativos para cada estrutura

## Tecnologias Utilizadas
* Linguagem C
* GCC (GNU Compiler Collection)
* Estruturas de dados implementadas sem bibliotecas externas

## Conceitos Aplicados
* Vetores estáticos
* Alocação dinâmica de memória (`malloc` e `free`)
* Ponteiros
* Listas encadeadas
* Controle de índices
* Aritmética modular para filas circulares
* Modularização com arquivos `.c` e `.h`

## Dificuldades Encontradas
Durante o desenvolvimento, os principais desafios foram:

* Implementação da lógica circular nas filas circulares e filas duplas.
* Gerenciamento correto de ponteiros e liberação de memória para evitar vazamentos.
* Configuração e compilação do projeto modularizado utilizando GCC fora de IDEs automatizadas.
* Integração dos módulos desenvolvidos pelos diferentes integrantes.

## Como Compilar

```bash
gcc *.c -o simulador
```

## Como Executar

```bash
.\simulador.exe
```

## Objetivo Acadêmico
O projeto teve como objetivo consolidar os conceitos teóricos de estruturas de dados lineares através da implementação prática em linguagem C, proporcionando maior compreensão sobre gerenciamento de memória, manipulação de ponteiros e organização modular de sistemas.