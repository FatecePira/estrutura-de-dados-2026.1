# 📚 Simulador de Estruturas de Dados

Um projeto educacional que implementa e simula diversas estruturas de dados fundamentais.

## 📖 Sobre o Projeto

Este é um trabalho acadêmico da disciplina de Estrutura de Dados (ATD2 - Atividade Disciplinar 2) desenvolvido para demonstrar a implementação e o funcionamento de estruturas de dados essenciais na Ciência da Computação. O projeto oferece uma interface interativa que permite testar operações em diferentes estruturas.

## 👥 Autores

Este projeto foi desenvolvido colaborativamente por:

| Autor | Responsabilidade |
|--------|------------------|
| **Julia Caroline Bronze** | Menu Principal, Interface com Usuário, Pilha |
| **Lucas Antonio Bertin Silva** | Implementação de Listas (Sequencial e Simplesmente Encadeada) |
| **Phelipe Cauduro Pereira** | Implementação de Filas (Fila, Circular, Dupla e Prioridade) |

## 🎯 Estruturas de Dados Implementadas

O simulador implementa as seguintes estruturas de dados:

1. **Lista Sequencial** - Armazenamento contíguo de elementos
2. **Lista Simplesmente Encadeada** - Elementos ligados através de ponteiros
3. **Pilha (Stack)** - LIFO (Last In, First Out)
4. **Fila (Queue)** - FIFO (First In, First Out)
5. **Fila Circular** - Fila com reutilização de espaço
6. **Fila Dupla (Deque)** - Inserção e remoção em ambas as extremidades
7. **Fila de Prioridade** - Elementos ordenados por prioridade

## 📁 Estrutura do Projeto

```
ATD2-Estrutura-de-Dados/
├── Main.c                          # Programa principal com menu interativo
├── Makefile                        # Script de automação de compilação
├── README.md                        # Este arquivo
└── biblioteca/                      # Pasta contendo as implementações
    ├── pilha.c / pilha.h           # Implementação de Pilha
    ├── listaSequencial.c / listaSequencial.h           # Implementação de Lista Sequencial
    ├── listaSimplesEncadeada.c / listaSimplesEncadeada.h  # Implementação de Lista Encadeada
    ├── fila.c / fila.h             # Implementação de Fila
    ├── filaCircular.c / filaCircular.h                 # Implementação de Fila Circular
    ├── filaDupla.c / filaDupla.h                       # Implementação de Fila Dupla
    └── filaDePrioridade.c / filaDePrioridade.h        # Implementação de Fila de Prioridade
```

## 📋 Como Usar

1. O programa exibirá um menu principal com todas as estruturas de dados disponíveis
2. Selecione o número correspondente à estrutura que deseja testar
3. Siga as instruções do submenu para realizar operações como:
   - **Inserir** elementos
   - **Remover** elementos
   - **Exibir** conteúdo
   - **Consultar** informações (tamanho, vazio, cheio)
4. Digite `0` para sair do programa

## 💡 Exemplo de Menu Principal

```
=====================================
 SIMULADOR DE ESTRUTURAS DE DADOS
=====================================
1 - Lista Sequencial
2 - Lista Simplesmente Encadeada
3 - Pilha
4 - Fila
5 - Fila Circular
6 - Fila Dupla
7 - Fila de Prioridade
0 - Sair

Escolha uma estrutura:
```

## 📝 Detalhes Técnicos

- **Linguagem**: C
- **Compilador Testado**: GCC

## 📚 Conceitos Abordados

- Estruturas de dados lineares
- Alocação dinâmica de memória
- Ponteiros e referências
- Operações básicas (inserção, remoção, busca)
- Implementação de TADs (Tipos Abstratos de Dados)

## ⚠️ Limitações Conhecidas

- Entrada de dados limitada a inteiros (conforme implementação)
- Sem persistência de dados (dados são perdidos ao encerrar o programa)

**FATECE | Faculdade de Tecnologia, Ciência e Educação | 2026**
