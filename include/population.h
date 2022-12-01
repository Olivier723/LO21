#ifndef POPULATION_H
#define POPULATION_H

#include "individual.h"

typedef struct Population
{
    LinkedList* individuals;
    int size;
} Population;

void freePopulation(Population* population);
void selectBestOfPopulation(Population* population, short tSelect);
void crossPopulation(Population* population, double pCroise);
void printPop(Population* pop);
Population* initPopulation(short populationSize, short individualSize);

#endif