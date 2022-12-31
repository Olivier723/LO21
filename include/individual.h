#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "linkedList.h"

typedef unsigned char Bit;

typedef struct Individual
{
    LinkedList* bitList;
    int size;
} Individual;


void swapBitLists(LinkedList* bitList1, LinkedList* bitList2, double pCroise);

void printIndividual(Individual *individual);

Individual* initIndividual(short longIndiv);

Individual* copyIndividual(Individual* toCopy);

/**
 * @brief Returns the quality index associatied with the individual by using one the two formulas
 */
double getIndividualQuality(Individual* individual);

double getIndividualQuality2(Individual* individual);

void freeIndividual(void* individual);

#endif