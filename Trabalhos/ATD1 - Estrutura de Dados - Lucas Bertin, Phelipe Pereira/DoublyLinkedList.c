#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "DoublyLinkedList.h"

DoublyLinkedList *createEmptyList()
{
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    if (list == NULL)
    {
        return NULL;
    }
    list->first = NULL;
    list->last = NULL;
    list->listSize = 0;

    return list;
};

static Node *createEmptyNode()
{

    Node *node = malloc(sizeof(Node));
    if (node == NULL)
    {
        return NULL;
    }

    node->data = NULL;
    node->next = NULL;
    node->previous = NULL;

    return node;
};

static Book *createData(int bookId, char title[MAX_TITLE], char authorName[MAX_NAME], int publishYear, int numberOfCopies)
{
    Book *data = malloc(sizeof(Book));
    if (data == NULL)
    {
        return NULL;
    }
    data->bookId = bookId;

    strncpy(data->title, title, MAX_TITLE - 1);
    data->title[MAX_TITLE - 1] = '\0';

    strncpy(data->authorName, authorName, MAX_NAME - 1);
    data->authorName[MAX_NAME - 1] = '\0';

    data->publishYear = publishYear;
    data->numberOfCopies = numberOfCopies;

    return data;
}

void pushBack(DoublyLinkedList *list, int bookId, char title[MAX_TITLE], char authorName[MAX_NAME], int publishYear, int numberOfCopies)
{
    if (list->last == NULL)
    {
        Node *node = createEmptyNode();
        node->data = createData(bookId, title, authorName, publishYear, numberOfCopies);
        if (node->data == NULL)
        {
            free(node);
            return;
        }
        list->first = node;
        list->last = node;
        list->listSize += 1;
        return;
    }

    Node *node = createEmptyNode();
    node->data = createData(bookId, title, authorName, publishYear, numberOfCopies);
    if (node->data == NULL)
    {
        free(node);
        return;
    }
    node->previous = list->last;
    list->last->next = node;
    list->last = node;
    list->listSize += 1;
};

void pushFront(DoublyLinkedList *list, int bookId, char title[MAX_TITLE], char authorName[MAX_NAME], int publishYear, int numberOfCopies)
{
    if (list->first == NULL)
    {
        Node *node = createEmptyNode();
        node->data = createData(bookId, title, authorName, publishYear, numberOfCopies);
        list->first = node;
        list->last = node;
        list->listSize += 1;
        return;
    }

    Node *node = createEmptyNode();
    node->data = createData(bookId, title, authorName, publishYear, numberOfCopies);
    node->next = list->first;
    list->first->previous = node;
    list->first = node;
    list->listSize += 1;
};

void removeById(DoublyLinkedList *list, int id)
{
    Node *current = list->first;

    while (current != NULL)
    {

        if (current->data->bookId == id)
        {

            // Caso: único nó
            if (current == list->first && current == list->last)
            {
                list->first = NULL;
                list->last = NULL;
            }
            // Caso: primeiro nó
            else if (current == list->first)
            {
                list->first = current->next;
                list->first->previous = NULL;
            }
            // Caso: último nó
            else if (current == list->last)
            {
                list->last = current->previous;
                list->last->next = NULL;
            }
            // Caso: meio
            else
            {
                current->previous->next = current->next;
                current->next->previous = current->previous;
            }

            free(current->data);
            free(current);
            list->listSize--;

            return;
        }

        current = current->next;
    }
}

Book *searchById(DoublyLinkedList *list, int id)
{
    Node *current = list->first;

    while (current != NULL)
    {
        if (current->data->bookId == id)
        {
            return current->data;
        }
        current = current->next;
    }

    return NULL;
}

void printList(DoublyLinkedList *list)
{
    Node *current = list->first;

    while (current != NULL)
    {
        Book *b = current->data;

        printf("ID: %d | Title: %s | Author: %s | Year: %d | Copies: %d\n",
               b->bookId, b->title, b->authorName,
               b->publishYear, b->numberOfCopies);

        current = current->next;
    }
};

void printListBackwards(DoublyLinkedList *list)
{
    Node *current = list->last;

    while (current != NULL)
    {
        Book *b = current->data;

        printf("ID: %d | Title: %s | Author: %s | Year: %d | Copies: %d\n",
               b->bookId, b->title, b->authorName,
               b->publishYear, b->numberOfCopies);

        current = current->previous;
    }
};

int getListSize(DoublyLinkedList *list)
{
    return list->listSize;
};

void freeList(DoublyLinkedList *list)
{
    Node *current = list->first;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);

    // #GarbageCollectorIsLife
};