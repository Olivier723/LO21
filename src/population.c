#include "../include/population.h"
#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>

void printPop(Population* pop){
    for(int i = 0; i < pop->size; i++){
        printf("Individu %d\nBitlist : ",i);
        Individual* indiv = LinkedList_Get(pop->individuals,i);
        printIndividual(indiv);
        printf("\n");
    }
}

void freePopulation(Population* population){
    LinkedList_Free(population->individuals, freeIndividual);
    free(population);
}

void selectBestOfPopulation(Population* population, short tSelect){
    for(int i = tSelect; i < population->size; ++i){
        int j = i % tSelect;
        freeIndividual(LinkedList_Get(population->individuals, i));
        LinkedList_ChangeNodeValue(population->individuals, copyIndividual(LinkedList_Get(population->individuals, j)), i);
    }
}

void crossPopulation(Population* population, double pCroise){
    for(int i = 0; i < population->size/2; i++){
        short rand1 = rand()%population->size;
        short rand2 = rand()%population->size;
        while(rand2 == rand1){
            rand2 = rand()%population->size;
        }
        Individual* indiv1 = LinkedList_Get(population->individuals, rand1);
        Individual* indiv2 = LinkedList_Get(population->individuals, rand2);
        swapBitLists(indiv1->bitList, indiv2->bitList, pCroise);
    }
}

Population* initPopulation(short populationSize, short individualSize){
    Population* population = malloc(sizeof(Population));
    if(!population) return NULL;
    population->individuals = createLinkedList();
    population->size = populationSize;
    for(short i = 0; i < populationSize; i++){
        Individual* new_individual = initIndividual(individualSize);
        LinkedList_Append(population->individuals, new_individual);
    }
    return population;
}