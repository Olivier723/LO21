#include "../include/population.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void askUser(int* var, const char* askPhrase){
    printf(askPhrase);
    scanf("%i", var);
}

int main(){
    int tSelect, popSize, indivSize, nGen = 10;
    askUser(&popSize, "Entez une taille pour la population :\n");
    askUser(&indivSize, "Entrez une taille pour les individus :\n");
    srand(time(NULL));
    Population* pop = initPopulation(popSize, indivSize);
    assert(pop != NULL);
    printPop(pop);
    for(int i = 0; i < nGen; i++){
        // //Doesn't work
        // crossPopulation(pop);
        // quickSort(pop->individuals,0,9);
        // selectBestOfPopulation(pop, 4)
    }
    return EXIT_SUCCESS;
}