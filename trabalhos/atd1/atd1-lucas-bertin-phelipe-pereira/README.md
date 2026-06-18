# Projeto — Lista Duplamente Encadeada para Biblioteca

## Integrantes
- Lucas Antonio Bertin Silva
- Phelipe Cauduro Pereira

---

## Estrutura do Projeto

Foi desenvolvida uma **lista duplamente encadeada** para armazenar e gerenciar os registros de livros de uma biblioteca.

A lista é composta por **três estruturas principais**:

### `Book`
Responsável por armazenar os dados dos livros.

### `Node`
Representa um nó da lista, contendo:
- Um ponteiro para `Book`
- Um ponteiro para o próximo nó
- Um ponteiro para o nó anterior

### `DoublyLinkedList`
Representa a lista em si, contendo:
- Um ponteiro para o primeiro nó
- Um ponteiro para o último nó
- O tamanho da lista

---

# DoublyLinkedList — Documentação das Funções

## `DoublyLinkedList *createEmptyList()`
Cria e inicializa uma lista vazia.

---

## `void pushBack(DoublyLinkedList *list, int bookId, char title[MAX_TITLE], char authorName[MAX_NAME], int publishYear, int numberOfCopies)`
Insere um novo livro no **final** da lista.

---

## `void pushFront(DoublyLinkedList *list, int bookId, char title[MAX_TITLE], char authorName[MAX_NAME], int publishYear, int numberOfCopies)`
Insere um novo livro no **início** da lista.

---

## `void removeById(DoublyLinkedList *list, int id)`
Remove da lista o livro que possui o `bookId` informado.

---

## `Book* searchById(DoublyLinkedList *list, int id)`
Busca e retorna o livro com o `bookId` informado.

---

## `void printList(DoublyLinkedList *list)`
Imprime todos os livros do início para o fim.

---

## `void printListBackwards(DoublyLinkedList *list)`
Imprime todos os livros do fim para o início.

---

## `int getListSize(DoublyLinkedList *list)`
Retorna a quantidade de elementos na lista.

---

## `void freeList(DoublyLinkedList *list)`
Libera toda a memória utilizada pela lista.

---

## Principais Dificuldades Enfrentadas

Durante o desenvolvimento do projeto, as principais dificuldades estiveram relacionadas ao gerenciamento de visibilidade interno e controle da memória dinâmica, para garantir que não ouvesse vazamentos.