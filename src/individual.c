#include "../include/individual.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define FORMULA 1

void printBit(void *bit)
{
    Bit *tempBit = bit;
    printf("%d", *tempBit);
}

void printIndividual(Individual *individual)
{
    LinkedList_Print(individual->bitList, printBit);
    printf("value : %f\n", getIndividualQuality(individual));
}

void freeIndividual(void *individual)
{
    Individual* indiv = individual;
    LinkedList_Free(indiv->bitList,free);
    free(indiv);
}

void initBitListIterative(LinkedList *bitList, int longIndiv)
{
    for (int i = 0; i < longIndiv; i++)
    {
        Bit *bit = malloc(sizeof(Bit));
        *bit = rand() % 2;
        LinkedList_Append(bitList, bit);
    }
}

void initBitListRecursive(LinkedList *bitList, int longIndiv)
{
    if (longIndiv != 0)
    {
        Bit *bit = malloc(sizeof(Bit));
        *bit = rand() % 2;
        LinkedList_Append(bitList, bit);
        initBitListRecursive(bitList, longIndiv - 1);
    }
}

long bitsToInt(LinkedList *bitList)
{
    long result = 0;
    for (unsigned long i = 0; i < bitList->listLength; i++)
    {
        Bit *currentBit = LinkedList_Get(bitList, i);
        if (*currentBit == 1)
            result += pow(2, bitList->listLength - i - 1);
    }
    return result;
}

void swapBitLists(LinkedList *bitList1, LinkedList *bitList2, double pCroise){
    if (bitList1->listLength != bitList2->listLength)
        return;
    char probability = floor(pCroise * 100);
    for (unsigned long i = 0; i < bitList1->listLength; i++)
    {
        char random = rand() % 101;
        if (random <= probability && pCroise != 0)
        {
            void *temp = LinkedList_Get(bitList1, i);
            LinkedList_ChangeNodeValue(bitList1, LinkedList_Get(bitList2, i), i);
            LinkedList_ChangeNodeValue(bitList2, temp, i);
        }
    }
}

double formula(double a, double b, Individual* individual){
    long quotient = pow(2,individual->size);
    long x = bitsToInt(individual->bitList);
    double X = (((double)x/(double)quotient)*(b-a)+a);
    return X;
}

double getIndividualQuality(Individual *individual)
{
    double X = formula(-1.f ,1.f ,individual);
    return ((-1) * pow(X, 2));
}

double getIndividualQuality2(Individual* individual){
    double X = formula(0.1f, 5.f, individual);
    return -1*log(X);
}

Individual *initIndividual(short longIndiv)
{
    Individual *individual = malloc(sizeof(Individual));
    if (!individual) return NULL;
    individual->bitList = createLinkedList();
    individual->size = longIndiv;
    initBitListIterative(individual->bitList, longIndiv);
    return individual;
}

void* bitCopy(void* toCopy){
    Bit* bit = malloc(sizeof(Bit));
    *bit = *((Bit*)toCopy);
    return bit;
}

Individual* copyIndividual(Individual* toCopy){
    Individual* individual = malloc(sizeof(Individual));
    individual->size = toCopy->size;
    individual->bitList = LinkedList_Copy(toCopy->bitList, bitCopy);
    return individual;
}