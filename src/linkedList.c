#include "../include/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node *LinkedList_GetNode(LinkedList *linkedlist, unsigned long nodePos) // ✓
{
    if (nodePos >= linkedlist->listLength)
        return NULL;
    if (nodePos == linkedlist->listLength - 1)
        return linkedlist->end;
    Node *node = linkedlist->start;
    for (unsigned long i = 0; i < nodePos; i++)
        node = node->next;
    return node;
}

void *LinkedList_Get(LinkedList *linkedlist, unsigned long index) // ✓
{
    if (index >= linkedlist->listLength)
        return NULL;
    Node *currentNode = LinkedList_GetNode(linkedlist, index);
    // if (currentNode != NULL)
    return currentNode->pointer;
}

void LinkedList_Swap(LinkedList *linkedlist, unsigned long pos1, unsigned long pos2) // ✓
{
    if (pos1 >= linkedlist->listLength || pos2 >= linkedlist->listLength)
        return;
    void *temp = LinkedList_Get(linkedlist, pos1);
    LinkedList_ChangeNodeValue(linkedlist, LinkedList_Get(linkedlist, pos2), pos1);
    LinkedList_ChangeNodeValue(linkedlist, temp, pos2);
}

void LinkedList_ChangeNodeValue(LinkedList *linkedlist, void *item, unsigned long index) // ✓
{
    if(index >= linkedlist->listLength) return;
    Node *tempNode = LinkedList_GetNode(linkedlist, index);
    tempNode->pointer = item;
}

void LinkedList_Print(LinkedList *linkedlist, void (*printFunc)(void *)) // ✓
{
    if (LinkedList_isEmpty(linkedlist))
        return;
    Node *currentNode = linkedlist->start;
    for (unsigned long i = 0; i < linkedlist->listLength - 1; i++)
    {
        printFunc(currentNode->pointer);
        currentNode = currentNode->next;
        printf("->");
    }
    printFunc(currentNode->pointer);
    printf("\n");
}

int LinkedList_isEmpty(LinkedList *linkedlist) // ✓
{
    return linkedlist->start == NULL;
}

void LinkedList_Free(LinkedList *linkedlist, void(*freeElemFunc)(void*))
{
    if(LinkedList_isEmpty(linkedlist)){
        free(linkedlist);
        return;
    }
    for(unsigned long i = linkedlist->listLength - 1; i != 0; i--){
        Node* tempNode = LinkedList_GetNode(linkedlist, i);
        freeElemFunc(tempNode->pointer);
        free(tempNode);
    }
    free(linkedlist);
}

void LinkedList_Free2(LinkedList *linkedlist, void(*freeElemFunc)(void*))
{
    Node **tempList = malloc(sizeof(Node *) * linkedlist->listLength);
    Node *currentNode = linkedlist->start;
    for (unsigned long i = 0; i < linkedlist->listLength; i++)
    {
        tempList[i] = currentNode;
        currentNode = currentNode->next;
    }
    for (unsigned long j = 0; j < linkedlist->listLength; j++)
    {
        freeElemFunc(tempList[j]->pointer);
        free(tempList[j]);
    }
    free(linkedlist);
    free(tempList);
}

void LinkedList_Remove(LinkedList *linkedlist, unsigned long index) // ✓
{
    if (index >= linkedlist->listLength)
        return;
    Node *toFree;
    if (index == 0)
    {
        toFree = linkedlist->start;
        linkedlist->start = toFree->next;
        free(toFree);
        linkedlist->listLength--;
        return;
    }
    Node *currentNode = LinkedList_GetNode(linkedlist, index - 1);
    toFree = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(toFree);
    linkedlist->listLength--;
}

void LinkedList_Insert(LinkedList *linkedlist, void *item, unsigned long index) // ✓
{
    if (index > linkedlist->listLength)
        return;
    if (linkedlist->listLength - 1 == index)
    {
        LinkedList_Append(linkedlist, item);
        return;
    }
    Node *newNode = malloc(sizeof(Node));
    newNode->pointer = item;
    linkedlist->listLength++;
    Node *tempNode;
    if (index == 0)
    {
        tempNode = linkedlist->start;
        linkedlist->start = newNode;
        newNode->next = tempNode;
        return;
    }
    Node *currentNode = LinkedList_GetNode(linkedlist, index - 1);
    tempNode = currentNode->next;
    currentNode->next = newNode;
    newNode->next = tempNode;
}

void LinkedList_Append(LinkedList *linkedlist, void *item) // ✓
{
    Node *newNode = malloc(sizeof(Node));
    newNode->pointer = item;
    newNode->next = NULL;
    linkedlist->listLength++;
    if (LinkedList_isEmpty(linkedlist))
    {
        linkedlist->start = newNode;
        linkedlist->end = newNode;
        return;
    }
    linkedlist->end->next = newNode;
    linkedlist->end = newNode;
}

void LinkedList_ToDynamic(LinkedList *linkedList, void **dynamicList)
{
    for (unsigned long i = 0; i < linkedList->listLength; i++)
    {
        dynamicList[i] = LinkedList_Get(linkedList, i);
    }
}

LinkedList *createLinkedList() // ✓
{
    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    linkedlist->start = NULL;
    linkedlist->end = NULL;
    linkedlist->listLength = 0;
    return linkedlist;
}
