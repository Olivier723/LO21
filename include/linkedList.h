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
    unsigned long listLength;
};

void LinkedList_SwapNodes(LinkedList* linkedlist, unsigned long pos1, unsigned long pos2);
void LinkedList_Swap(LinkedList *list, unsigned long pos1, unsigned long pos2);
void LinkedList_Print(LinkedList* linkedlist, void (*printFunc)(void*));
int LinkedList_isEmpty(LinkedList* linkedlist);
void LinkedList_Free(LinkedList* linkedlist);
void LinkedList_Remove(LinkedList* linkedlist, unsigned long index);
void LinkedList_Insert(LinkedList* linkedlist, void* item,unsigned long index);
void LinkedList_Append(LinkedList* linkedlist, void* item);
void* LinkedList_Get(LinkedList* linkedlist, unsigned long index);
LinkedList* createLinkedList();

#endif
