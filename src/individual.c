#include "../include/individual.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void freeIndividual(Individual* individual){
    LinkedList_Free(individual->bitList);
    free(individual);
}

void initBitListIterative(LinkedList* bitList, int longIndiv){
    for(int i = 0; i < longIndiv; i++){
        Bit bit = rand()%2;
        LinkedList_Append(bitList, &bit);
    }
}

void initBitListRecursive(LinkedList* bitList, int longIndiv){
    if(longIndiv != 0){
        Bit bit = rand()%2;
        LinkedList_Append(bitList, &bit);
        initBitListRecursive(bitList, longIndiv-1);
    }
}

int bitsToInt(LinkedList* bitList){
    int result = 0;
    for(int i = 0; i < bitList->listLength; i++){
        int* currentBit = LinkedList_Get(bitList,i);
        if(*currentBit)  result += pow(2,bitList->listLength - i);
    }
    return result;
}

void swapBitLists(LinkedList* bitList1, LinkedList* bitList2, double pCroise){
    if (bitList1->listLength != bitList2->listLength) return;
    int probability = floor(pCroise * 100);
    for(int i = 0; i < bitList1->listLength; i++){
        int random = rand()%101;
        if(random <= probability){
            Bit* temp = (Bit*)LinkedList_Get(bitList1, i);
            LinkedList_Remove(bitList1, i);
            LinkedList_Insert(bitList1, LinkedList_Get(bitList2, i), i);
            LinkedList_Remove(bitList2, i);
            LinkedList_Insert(bitList2, temp, i);
        }
    }
}

double getIndividualQuality(Individual* individual){
    int longIndividual = individual->longIndiv;
    int x = bitsToInt(individual->bitList);
    double X = (x / 2<<(longIndividual - 2))+1;
    return ((-1)*pow(X,2));
}

Individual* initIndividual(int longIndiv){
    Individual* individual = malloc(sizeof(Individual));
    if(!individual) return NULL;
    individual->bitList = createLinkedList();
    individual->longIndiv = longIndiv;
    initBitListRecursive(individual->bitList, longIndiv);
    return individual;
}