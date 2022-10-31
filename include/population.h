#ifndef POPULATION_H
#define POPULATION_H

#include "individual.h"

typedef struct Population
{
    LinkedList* individuals;
    int size;
} Population;
Population* initPopulation(int populationSize, int individualSize);

#endif