#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
    unsigned long listLength;
};

//Changes the value stored in the node at index position
void LinkedList_ChangeNodeValue(LinkedList* linkedlist, void* Elem, unsigned long index);

/*
@param pos1 The position of the node 1
@param pos2 The position of the node 2
Swaps the values of both nodes
*/
void LinkedList_Swap(LinkedList *list, unsigned long pos1, unsigned long pos2);

void LinkedList_Print(LinkedList* linkedlist, void (*printFunc)(void*));

int LinkedList_isEmpty(LinkedList* linkedlist);

void LinkedList_Free(LinkedList* linkedlist, void(*freeElemFunc)(void*));

void LinkedList_Free2(LinkedList *linkedlist, void(*freeElemFunc)(void*));

void LinkedList_Remove(LinkedList* linkedlist, unsigned long index);

void LinkedList_Insert(LinkedList* linkedlist, void* Elem,unsigned long index);

void LinkedList_Append(LinkedList* linkedlist, void* Elem);

//Gets the value stored in the node at index
void* LinkedList_Get(LinkedList* linkedlist, unsigned long index);

LinkedList* createLinkedList();

#endif
