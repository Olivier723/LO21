#include "../include/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

// Node* LinkedList_getNode(LinkedList* linkedlist, int index){

// }

void LinkedList_Print(LinkedList* linkedlist, void (*printFunc)(void*)){
    Node* tempNode = linkedlist->start;
    for(int i =0; i<linkedlist->listLength; i++){
        printFunc(tempNode->pointer);
        tempNode = tempNode->next;
        printf("->");
    }
}

int LinkedList_isEmpty(LinkedList* linkedlist){
    return linkedlist->start == NULL;
}

void LinkedList_Free(LinkedList* linkedlist){
    Node** tempList = malloc(sizeof(Node*)*linkedlist->listLength);
    for(int i = 0; i < linkedlist->listLength; i++){
        tempList[i] = LinkedList_Get(linkedlist, i);
    }
    for(int j = 0; j < linkedlist->listLength; j++){
        free(tempList[j]);
    }
    free(linkedlist);
    free(tempList);
}

void LinkedList_Remove(LinkedList* linkedlist, int index){
    if(index >= linkedlist->listLength) return;
    Node* tempNode = linkedlist->start;
    for(int i = 0; i < index-1; i++){
        tempNode = tempNode->next;
    }
    Node* toFree = tempNode->next;
    tempNode->next = tempNode->next->next;
    free(toFree);
}

void LinkedList_Insert(LinkedList* linkedlist,void* piece, int index){
    if(index < linkedlist->listLength-1){
        Node* newNode = malloc(sizeof(Node));
        newNode->pointer = piece;
        linkedlist->listLength++;
        Node* tempNode = linkedlist->start;
        for(int i = 0; i < index; i++){
            tempNode = tempNode->next;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }else if(index == linkedlist->listLength-1){
        LinkedList_Append(linkedlist,piece);
    }
}

void LinkedList_Append(LinkedList *linkedlist, void* piece)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->pointer = piece;
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

void* LinkedList_Get(LinkedList *linkedlist, int index)
{
    if (index >= linkedlist->listLength) return NULL;
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