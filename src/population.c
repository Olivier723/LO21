#include "../include/population.h"
#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>

void freePopulation(Population* population){
    for(int i = 0; i < population->size; i++){
        Individual* temp_individual = LinkedList_Get(population->individuals, i);
        freeIndividual(temp_individual);
    }
    free(population->individuals);
    free(population);
}

void selectBestOfPopulation(Population* population, int tSelect){
    Individual** tempList = malloc(sizeof(Individual*)*tSelect);
    for(int i = 0; i < tSelect; i++){
        tempList[i] = (Individual*)LinkedList_Get(population->individuals, i); 
    }
    for(int j = 0; j < population->size; j++){
        int k = j % 4;
        LinkedList_Remove(population->individuals, j);
        LinkedList_Insert(population->individuals, tempList[k], j);
    }
}

Population* crossPopulation(Population* population){
    Population* newPopulation = malloc(sizeof(Population));
    if (!newPopulation) return NULL;
    newPopulation->individuals = createLinkedList();
    newPopulation->size = population->size;
    for(int i = 0; i < newPopulation->size; i++){
        int rand1 = rand()%newPopulation->size;
        int rand2 = rand()%newPopulation->size;
        while(rand2 == rand1){
            rand2 = rand()%newPopulation->size;
        }
        Individual* indiv1 = LinkedList_Get(population->individuals, rand1);
        Individual* indiv2 = LinkedList_Get(population->individuals, rand2);
        
    }
    return newPopulation;
}

Population* initPopulation(int populationSize, int individualSize){
    Population* population = malloc(sizeof(Population));
    if(!population) return NULL;
    population->individuals = createLinkedList();
    population->size = populationSize;
    for(int i = 0; i < populationSize; i++){
        Individual* new_individual = initIndividual(individualSize);
        LinkedList_Append(population->individuals, new_individual);
    }
    quickSort(population->individuals,0,populationSize-1);
    printf("Bruh");
    return population;
}