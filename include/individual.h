#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "linkedList.h"

typedef unsigned char Bit;

typedef struct Individual
{
    LinkedList *bitList;
    int longIndiv;
} Individual;

/*
@param pCroise a probabilty between 0 and 1
*/
void swapBitLists(LinkedList *bitList1, LinkedList *bitList2, double pCroise);

Individual *initIndividual(int longIndiv);
double getIndividualQuality(Individual *individual);
void freeIndividual(Individual *individual);

void printBit(void *bit);

#endif