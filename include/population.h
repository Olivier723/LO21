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

/**
 * @brief Initialize a population with populationSize individuals
 * 
 * @param populationSize 
 * @param individualSize 
 * @return Population* 
 */
Population* initPopulation(short populationSize, short individualSize);

#endif