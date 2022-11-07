#include "../include/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node* LinkedList_GetNode(LinkedList* linkedlist, unsigned long nodePos){
    if(LinkedList_isEmpty(linkedlist) || nodePos >= linkedlist->listLength)
        return NULL;
    Node* node = linkedlist->listLength;
    for(int i = 0; i < nodePos; i++) node = node->next;
    return node;
}

void LinkedList_SwapNodes(LinkedList* linkedlist, unsigned long pos1, unsigned long pos2){
    if(LinkedList_isEmpty(linkedlist) || pos1 >= linkedlist->listLength || pos2 >= linkedlist->listLength)
        return;
    
    if(pos1 == pos2)
        return;

    if(pos1 > pos2)
        LinkedList_SwapNodes(linkedlist, pos2, pos1);
        return;

    if(pos1 == 0){
        Node* node1 = linkedlist->start;
        Node* node2 = LinkedList_GetNode(linkedlist, pos2-1);
        Node* temp = node2->next;
        node2->next = node1;
        linkedlist->start = temp;
    }
    else{
        Node* node1 = LinkedList_GetNode(linkedlist, pos1-1);
        Node* node2 = LinkedList_GetNode(linkedlist, pos2-1); 
        Node* temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    }
}

void LinkedList_Swap(LinkedList *linkedlist, unsigned long pos1, unsigned long pos2)
{
    if(LinkedList_isEmpty(linkedlist) || pos1 >= linkedlist->listLength || pos2 >= linkedlist->listLength)
        return;
    void *temp = LinkedList_Get(linkedlist, pos1);
    LinkedList_Remove(linkedlist, pos1);
    LinkedList_Insert(linkedlist, LinkedList_Get(linkedlist, pos2), pos1);
    LinkedList_Remove(linkedlist, pos2);
    LinkedList_Insert(linkedlist, temp, pos2);
}


void LinkedList_Print(LinkedList *linkedlist, void (*printFunc)(void *))
{
    if(LinkedList_isEmpty(linkedlist))
        return;
    Node *currentNode = linkedlist->start;
    for (int i = 0; i < linkedlist->listLength - 1; i++)
    {
        printFunc(currentNode->pointer);
        currentNode = currentNode->next;
        printf("->");
    }
    printFunc(currentNode->pointer);
    printf("\n");
}

int LinkedList_isEmpty(LinkedList *linkedlist)
{
    return linkedlist->start == NULL;
}

void LinkedList_Free(LinkedList *linkedlist)
{
    Node **tempList = malloc(sizeof(Node *) * linkedlist->listLength);
    Node *currentNode = linkedlist->start;
    for (int i = 0; i < linkedlist->listLength; i++)
    {
        tempList[i] = currentNode;
        currentNode = currentNode->next;
    }
    for (int j = 0; j < linkedlist->listLength; j++)
    {
        free(tempList[j]);
    }
    free(linkedlist);
    free(tempList);
}

void LinkedList_Remove(LinkedList *linkedlist, unsigned long index)
{
    if (LinkedList_isEmpty(linkedlist) || index >= linkedlist->listLength)
        return;
    Node *toFree;
    if (index == 0)
    {
        toFree = linkedlist->start;
        linkedlist->start = toFree->next;
    }
    else
    {
        Node *currentNode = linkedlist->start;
        for (int i = 0; i < index - 1; i++)
        {
            currentNode = currentNode->next;
        }
        toFree = currentNode->next;
        currentNode->next = currentNode->next->next;
    }
    free(toFree);
    linkedlist->listLength--;
}

void LinkedList_Insert(LinkedList *linkedlist, void *item, unsigned long index)
{
    if (index > linkedlist->listLength)
        return;
    Node *newNode = malloc(sizeof(Node));
    newNode->pointer = item;
    linkedlist->listLength++;
    Node *tempNode;
    if (index == 0)
    {
        tempNode = linkedlist->start;
        linkedlist->start = newNode;
        newNode->next = tempNode;
    }
    else
    {
        Node *currentNode = linkedlist->start;
        for (int i = 0; i < index - 1; i++)
        {
            currentNode = currentNode->next;
        }
        tempNode = currentNode->next;
        currentNode->next = newNode;
        newNode->next = tempNode;
    }
}

void LinkedList_Append(LinkedList *linkedlist, void *item)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->pointer = item;
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

void *LinkedList_Get(LinkedList *linkedlist, unsigned long index)
{
    if (index >= linkedlist->listLength)
        return NULL;
    if (index == linkedlist->listLength - 1)
    {
        return linkedlist->end->pointer;
    }
    Node *currentNode = linkedlist->start;
    for (int counter = 0; counter < index; counter++)
    {
        currentNode = currentNode->next;
    }
    return currentNode->pointer;
}

void LinkedList_ToDynamic(LinkedList *linkedList, void **dynamicList)
{
    for (int i = 0; i < linkedList->listLength; i++)
    {
        dynamicList[i] = LinkedList_Get(linkedList, i);
    }
}

LinkedList *createLinkedList()
{
    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    linkedlist->start = NULL;
    linkedlist->end = NULL;
    linkedlist->listLength = 0;
    return linkedlist;
}
