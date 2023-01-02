#include "../include/population.h"
#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#define POPSIZE 20
#define TSELECT 10
#define INDIVSIZE 16
#define NGEN 20
#define RECORD 1
#define PCROISE 0.4f

void recordPopulationEvolution(FILE *file, Population *pop, int iteration)
{
    fprintf(file, "Iteration %i\n", iteration);
    for (int i = 0; i < pop->size; i++)
    {
        fprintf(file, "\tIndividu %d\n\tBitlist : ", i);
        Individual *indiv = LinkedList_Get(pop->individuals, i);
        Node *currentNode = indiv->bitList->start;
        for (unsigned long j = 0; j < indiv->bitList->listLength - 1; j++)
        {
            Bit *tempBit = currentNode->pointer;
            fprintf(file, "%d", *tempBit);
            currentNode = currentNode->next;
            fprintf(file, "->");
        }
        Bit *tempBit = currentNode->pointer;
        fprintf(file, "%d\n\tquality : %f\n", *tempBit, getIndividualQuality2(indiv));
        fprintf(file, "\tvalue : %lu\n\n", bitsToInt(indiv->bitList));
    }
}


int main(){
    srand(time(NULL));
    Population* pop = initPopulation(POPSIZE, INDIVSIZE);
    assert(pop != NULL);
    FILE* f = NULL;
    if(RECORD){
        f = fopen("../Population_Records.txt","w");
    }
    for (short i = 0; i < NGEN; i++)
    {
        if (RECORD)
        {
            recordPopulationEvolution(f, pop, i);
        }
        crossPopulation(pop, PCROISE);
        quickSort(pop->individuals,0,POPSIZE-1);
        selectBestOfPopulation(pop, TSELECT);
    }
    if (RECORD)
    {
        fclose(f);
    }
    freePopulation(pop);
    return EXIT_SUCCESS;
}