#ifndef POPULATION_H
#define POPULATION_H

#include "individual.h"

typedef struct Population
{
    Individual** Individuals;
    int populationSize;
} Population;

#endif