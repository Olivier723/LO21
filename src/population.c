#include "../include/population.h"
#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>

void freePopulation(Population* population){
    for(int i = 0; i < population->size; i++){
        freeIndividual(population->individuals[i]);
    }
    free(population->individuals);
    free(population);
}

void selectBestOfPopulation(Population* population, int tSelect){
    Individual** tempList = malloc(sizeof(Individual*)*tSelect);
    for(int i = 0; i < tSelect; i++){
        tempList[i] = population->individuals[i]; 
    }
    for(int j = 0; j < population->size; j++){
        int k = j % 4;
        population->individuals[j] = tempList[k];
    }
}

Population* initPopulation(int populationSize, int individualSize){
    Population* population = malloc(sizeof(Population));
    if(!population) return NULL;
    population->individuals = malloc(sizeof(Individual*)*populationSize-1);
    population->size = populationSize;
    for(int i = 0; i < populationSize; i++){
        population->individuals[i] = initIndividual(individualSize);
    }
    quickSort(population->individuals,0,populationSize-1);

    return population;
}