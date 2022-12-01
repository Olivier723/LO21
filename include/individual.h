#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "linkedList.h"

typedef unsigned char Bit;

typedef struct Individual
{
    LinkedList* bitList;
    int size;
} Individual;

/*
@param pCroise a probability between 0 and 1
*/

void swapBitLists(LinkedList* bitList1, LinkedList* bitList2, double pCroise);

void printIndividual(Individual *individual);

Individual* initIndividual(short longIndiv);

Individual* copyIndividual(Individual* toCopy);

double getIndividualQuality(Individual* individual);

void freeIndividual(void* individual);

#endif