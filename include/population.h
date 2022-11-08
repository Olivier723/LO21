#ifndef POPULATION_H
#define POPULATION_H

#include "individual.h"

typedef struct Population
{
    LinkedList* individuals;
    int size;
} Population;

void selectBestOfPopulation(Population* population, int tSelect);
Population* crossPopulation(Population* population);
void printPop(Population* pop);
Population* initPopulation(int populationSize, int individualSize);

#endif