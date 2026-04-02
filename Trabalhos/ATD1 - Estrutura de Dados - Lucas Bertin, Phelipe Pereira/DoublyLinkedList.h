#define MAX_TITLE 100
#define MAX_NAME 100

typedef struct
{
    int bookId;
    char title[MAX_TITLE];
    char authorName[MAX_NAME];
    int publishYear;
    int numberOfCopies;
} Book;

typedef struct Node
{
    Book *data;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct
{
    Node *first;
    Node *last;
    int listSize;

} DoublyLinkedList;

DoublyLinkedList *createEmptyList();

void pushFront(DoublyLinkedList *list,
               int bookId, char title[MAX_TITLE], char authorName[MAX_NAME],
               int publishYear, int numberOfCopies);
void pushBack(DoublyLinkedList *list,
              int bookId, char title[MAX_TITLE], char authorName[MAX_NAME],
              int publishYear, int numberOfCopies);

void removeById(DoublyLinkedList *list, int id);
Book *searchById(DoublyLinkedList *list, int id);
void printList(DoublyLinkedList *list);
void printListBackwards(DoublyLinkedList *list);
int getListSize(DoublyLinkedList *list);
void freeList(DoublyLinkedList *list);