#include "../include/population.h"
#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

#define e_acc_aigu 130

short tSelect, popSize, indivSize, nGen;
double pCroise;
char enableRecord;

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

//Controls the inputs from the user
void getValuesFromUser(){
    printf("Entez une taille pour la population :\n");
    scanf("%hi", &popSize);
    while(popSize < 0){
        printf("La taille de la population doit etre positive \n");
        scanf("%hi", &popSize);
    }
    printf("Entrez une taille pour les individus :\n");
    scanf("%hi", &indivSize);
    while(indivSize < 0){
        printf("La taille d'un individu doit etre positive \n");
        scanf("%hi", &indivSize);
    }
    printf("Entrez le nombre d'it%crations de l'algorithme :\n",e_acc_aigu);
    scanf("%hi", &nGen);
    while(nGen < 0){
        printf("Le nombre d'it%crations doit etre positif \n",e_acc_aigu);
        scanf("%hi", &nGen);
    }
    printf("Entrez une propabilit%c de croisement entre individus (entre 0 et 1):\n",e_acc_aigu);
    scanf("%lf", &pCroise);
    while(pCroise > 1 || pCroise < 0){
        printf("La probabilit%c doit etre comprise entre 0 et 1 :\n",e_acc_aigu);
        scanf("%lf", &pCroise);
    }
    printf("Entrez le nombre d'individus a garder pour la nouvelle gen : ");
    scanf("%hi", &tSelect);
    while(tSelect < 0){
        printf("Le nombre d'individus doit etre positif \n");
        scanf("%hi", &tSelect);
    }
    do{
        printf("Souhaitez vous activer l'enregistrement de l'évolution de la population ? [O/N]\n");
        scanf("%c",&enableRecord);
    }while(enableRecord != 'O' || enableRecord != 'N');
}

int main(){
    srand(time(NULL));
    getValuesFromUser();
    Population* pop = initPopulation(popSize, indivSize);
    assert(pop != NULL);
    FILE* f = fopen("../Population_Records.txt","w");

    for(short i = 0; i < nGen; i++){
        recordPopulationEvolution(f,pop,i);
        crossPopulation(pop, pCroise);
        quickSort(pop->individuals,0,popSize-1);
        selectBestOfPopulation(pop, tSelect);
    }
    
    fclose(f);
    freePopulation(pop);
    return EXIT_SUCCESS;
}