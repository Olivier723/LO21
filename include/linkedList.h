#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
*The linked list with void pointer so that the list
*can take any type without rewriting the whole code each time
*/
typedef struct Node Node;
struct Node
{
    void *pointer;
    Node *next;
};

/*Encapsulates the linked in a single struct with the length to make it more convenient*/
typedef struct LinkedList LinkedList;
struct LinkedList
{
    Node *start;
    Node *end;
    size_t listLength;
};

void LinkedList_Print(LinkedList*, void (*printFunc)(void*));
int LinkedList_isEmpty(LinkedList*);
void LinkedList_Free(LinkedList*);
void LinkedList_Remove(LinkedList*, int);
void LinkedList_Insert(LinkedList*,void*,int);
void LinkedList_Append(LinkedList*,void*);
void* LinkedList_Get(LinkedList*,int);
LinkedList* createLinkedList();

#endif
