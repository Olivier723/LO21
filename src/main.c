#include "../include/population.h"
#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void recordPopulationEvolution(FILE* file, Population* pop, int iteration){
    fprintf(file,"Iteration %i\n",iteration);
    for(int i = 0; i < pop->size; i++){
        fprintf(file,"\tIndividu %d\n\tBitlist : ",i);
        Individual* indiv = LinkedList_Get(pop->individuals,i);
        Node *currentNode = indiv->bitList->start;
        for (unsigned long j = 0; j < indiv->bitList->listLength - 1; j++)
        {
            Bit *tempBit = currentNode->pointer;
            fprintf(file,"%d", *tempBit);
            currentNode = currentNode->next;
            fprintf(file,"->");
        }
        Bit *tempBit = currentNode->pointer;
        fprintf(file,"%d\n\tvalue : %file\n\n", *tempBit, getIndividualQuality(indiv));
    }

}

void askUser(int* var, const char* askPhrase){
    printf(askPhrase);
    scanf("%i", var);
}


int main(){
    srand(time(NULL));
    int tSelect, popSize, indivSize, nGen;
    double pCroise;
    askUser(&popSize, "Entez une taille pour la population :\n");
    askUser(&indivSize, "Entrez une taille pour les individus :\n");
    askUser(&nGen, "Entrez le nombre d'iterations de l'algorithme :\n");
    Population* pop = initPopulation(popSize, indivSize);
    assert(pop != NULL);
    printf("Entrez une propabilite de croisement entre individus :\n");
    scanf("%lf", &pCroise);
    askUser(&tSelect, "Entrez le nombre d'individus a garder pour la nouvelle gen : ");
    FILE* f = fopen("../Population_Records.txt","w");
    for(int i = 0; i < nGen; i++){
        recordPopulationEvolution(f,pop,i);
        crossPopulation(pop, pCroise);
        quickSort(pop->individuals,0,popSize-1);
        selectBestOfPopulation(pop, tSelect);
    }
    fclose(f);
    freePopulation(pop);
    return EXIT_SUCCESS;
}