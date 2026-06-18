ATD1 – Estrutura de dados

Integrantes

* Yuri Garcia
* Wellinton Chiesa

---

Descrição da Estrutura

O trabalho a seguir consiste na implementação de uma **lista duplamente encadeada em linguagem C**, utilizada para simular o gerenciamento de livros em uma estante de biblioteca.

Cada elemento da lista representa um livro e armazena as seguintes informações:

* Código do livro
* Título
* Autor
* Ano de publicação
* Quantidade de exemplares disponíveis

Além disso, cada nó possui dois ponteiros:

* 🔹 `proximo` → aponta para o próximo elemento
* 🔹 `anterior` → aponta para o elemento anterior

Essa estrutura permite navegação eficiente em ambas as direções (ida e volta).

---

Funcionalidades Implementadas

O sistema desenvolvido possui um menu interativo que permite realizar as seguintes operações:

1. Inserção de livro no início da lista
2. Inserção de livro no final da lista
3. Remoção de livro por código
4. Busca de livro por código
5. Listagem de livros (ordem normal)
6. Listagem de livros (ordem reversa)
7. Contagem total de livros

---

Explicação das Principais Funções

* **criarLista()**
  Responsável por inicializar a lista vazia.

* **criarNo()**
  Aloca memória dinamicamente para um novo nó e inicializa seus dados.

* **inserirInicio()**
  Insere um novo elemento no início da lista, atualizando corretamente os ponteiros.

* **inserirFinal()**
  Percorre a lista até o último elemento e realiza a inserção no final.

* **removerLivro()**
  Remove um nó com base no código informado, garantindo a integridade da lista e liberando a memória utilizada.

* **buscarLivro()**
  Realiza a busca sequencial de um livro pelo código e exibe seus dados.

* **imprimirLista()**
  Exibe os elementos da lista do primeiro ao último.

* **imprimirListaReversa()**
  Exibe os elementos do último ao primeiro, demonstrando a ligação dupla.

* **contarElementos()**
  Retorna a quantidade total de elementos presentes na lista.

* **limparLista()**
  Libera toda a memória alocada dinamicamente antes do encerramento do programa.

---

Dificuldades Encontradas

Durante o desenvolvimento, foram identificados alguns desafios importantes:

* Manipulação correta de ponteiros (`anterior` e `proximo`)
* Tratamento de casos especiais (lista vazia e remoção do primeiro nó)
* Uso adequado de alocação dinâmica (`malloc`) e liberação de memória (`free`)
* Organização das funções para manter o código modular e legível

---


 Conclusão

A implementação foi concluída com sucesso, atendendo a todos os requisitos propostos.
O sistema desenvolvido permite gerenciar dinamicamente uma coleção de livros, demonstrando na prática o uso de listas duplamente encadeadas.

---
