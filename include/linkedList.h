#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;
struct Node
{
    void *pointer;
    Node *next;
};

/*Encapsulates the linked list in a single struct with the length to make it more convenient*/
typedef struct LinkedList LinkedList;
struct LinkedList
{
    Node *start;
    Node *end;
    unsigned long listLength;
};

//Changes the value stored in the node at index position
void LinkedList_ChangeNodeValue(LinkedList* linkedlist, void* Elem, unsigned long index);

/**
 * @brief Swap to values in a linked list
 * 
 * @param list the list
 * @param pos1 the fist position
 * @param pos2 the second position
 */
void LinkedList_Swap(LinkedList *list, unsigned long pos1, unsigned long pos2);

/**
 * @brief Prints the linked_list
 * 
 * @param linkedlist the list to print
 * @param printFunc the function that prints the elements in the list
 */
void LinkedList_Print(LinkedList* linkedlist, void (*printFunc)(void*));

int LinkedList_isEmpty(LinkedList* linkedlist);

/**
 * @brief Frees a linked list
 * 
 * @param linkedlist 
 * @param freeElemFunc 
 */
void LinkedList_Free(LinkedList* linkedlist, void(*freeElemFunc)(void*));

/**
 * @brief Frees a linked list recursively, if linked is large you need to increase the recursive limit
 * 
 * @param linkedlist 
 * @param freeElemFunc 
 */
void LinkedList_FreeRec(LinkedList* linkedlist, void(*freeElemFunc)(void *));

/**
 * @brief Removes the element stored at index also deletes the node
 * 
 * @param linkedlist 
 * @param index 
 */
void LinkedList_Remove(LinkedList* linkedlist, unsigned long index);

/**
 * @brief  Inserts an element at index
 * 
 * @param linkedlist 
 * @param Elem 
 * @param index 
 */
void LinkedList_Insert(LinkedList* linkedlist, void* Elem, unsigned long index);

/**
 * @brief Adds a value at the end of the list
 * 
 * @param linkedlist 
 * @param Elem 
 */
void LinkedList_Append(LinkedList* linkedlist, void* Elem);

//Gets the value stored in the node at index
void* LinkedList_Get(LinkedList* linkedlist, unsigned long index);

/**
 * @brief Copies a linked list in a new linked list
 * 
 * @param toCopy the linked list to copy
 * @param copyElemFunc the function that copies the elements stored inside the list
 * @return LinkedList* a new linked list
 */
LinkedList* LinkedList_Copy(LinkedList* toCopy, void*(*copyElemFunc)(void*));

/**
 * @brief Create a Linked List object, if it fails returns NUll
 * 
 * @return LinkedList* 
 */
LinkedList* createLinkedList();

#endif
