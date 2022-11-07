#ifndef POPULATION_H
#define POPULATION_H

#include "individual.h"

typedef struct Population
{
    LinkedList* individuals;
    int size;
} Population;
void printPop(Population* pop);
Population* initPopulation(int populationSize, int individualSize);

#endif