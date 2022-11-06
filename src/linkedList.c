#include "../include/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void LinkedList_SwapNodes(LinkedList* linkedlist, unsigned long nodePos1, unsigned long nodePos2){
    if(nodePos1 >= linkedlist->listLength || nodePos2 >= linkedlist->listLength) return;
    if(nodePos1 == nodePos2) return;
    Node* node1 = linkedlist->start;
    for(int i = 0; i < nodePos1; i++) node1 = node1->next;
    Node* node2 = linkedlist->start;
    for(int i = 0; i < nodePos2; i++) node2 = node2->next;
    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

void LinkedList_Print(LinkedList* linkedlist, void (*printFunc)(void*)){
    Node* currentNode = linkedlist->start;
    for(int i =0; i<linkedlist->listLength-1; i++){
        printFunc(currentNode->pointer);
        currentNode = currentNode->next;
        printf("->");
    }
    printFunc(currentNode->pointer);
    printf("\n");
}

int LinkedList_isEmpty(LinkedList* linkedlist){
    return linkedlist->start == NULL;
}

void LinkedList_Free(LinkedList* linkedlist){
    Node** tempList = malloc(sizeof(Node*)*linkedlist->listLength);
    Node* currentNode = linkedlist->start;
    for(int i = 0; i < linkedlist->listLength; i++){
        tempList[i] = currentNode;
        currentNode = currentNode->next;
    }
    for(int j = 0; j < linkedlist->listLength; j++){
        free(tempList[j]);
    }
    free(linkedlist);
    free(tempList);
}

void LinkedList_Remove(LinkedList* linkedlist, unsigned long index){
    if(index >= linkedlist->listLength) return;
    Node* currentNode = linkedlist->start;
    for(int i = 0; i < index-1; i++){
        currentNode = currentNode->next;
    }
    Node* toFree = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(toFree);
    linkedlist->listLength--;
}

void LinkedList_Insert(LinkedList* linkedlist, void* piece, unsigned long index){
    if(index < linkedlist->listLength-1){
        Node* newNode = malloc(sizeof(Node));
        newNode->pointer = piece;
        linkedlist->listLength++;
        Node* currentNode = linkedlist->start;
        for(int i = 0; i < index-1; i++){
            currentNode = currentNode->next;
        }
        Node* tempNode = currentNode->next;
        currentNode->next = newNode;
        newNode->next = tempNode;
    }else if(index == linkedlist->listLength-1){
        LinkedList_Append(linkedlist,piece);
    }
}

void LinkedList_Append(LinkedList *linkedlist, void* piece){
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

void* LinkedList_Get(LinkedList *linkedlist, unsigned long index){
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

LinkedList* createLinkedList()
{
    LinkedList *linkedlist = malloc(sizeof(LinkedList));
    linkedlist->start = NULL;
    linkedlist->end = NULL;
    linkedlist->listLength = 0;
    return linkedlist;
}
