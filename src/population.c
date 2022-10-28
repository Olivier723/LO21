#include "../include/population.h"
#include "../include/quicksort.h"
#include <stdlib.h>

Population* selectBestOfPopulation(Population* population, int tSelect){
    Individual** tempList = malloc(sizeof(Individual*)*tSelect);
    for(int i = 0; i < tSelect; i++){
        tempList[i] = population->Individuals[i]; 
    }
    for(int j = 0; j < population->populationSize; j++){
        int k = j % 4;
        population->Individuals[j] = tempList[k];
    }
}

Population* initPopulation(int populationSize, int individualSize){
    Population* population = malloc(sizeof(Population));
    population->Individuals = malloc(sizeof(Individual*)*populationSize);
    population->populationSize = populationSize;
    for(int i = 0; i < populationSize; i++){
        population->Individuals[i] = initIndividual(individualSize);
    }
    quickSort(population->Individuals,0,populationSize);

    return population;
}