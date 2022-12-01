#include "../include/population.h"
#include "../include/quicksort.h"
#include "../external/getopt.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

short tSelect, popSize, indivSize, nGen, enableRecord;
double pCroise;

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
        fprintf(file, "%d\n\tvalue : %f\n\n", *tempBit, getIndividualQuality(indiv));
    }
}

int getValuesFromArgs(int argc, char** argv){
    const struct option options[] = {
        { .name = "popSize", .has_arg = required_argument, .flag = 0, .val = 'P'},
        { .name = "indivSize", .has_arg = required_argument, .flag = 0, .val = 'i' },
        { .name = "nGen", .has_arg = required_argument, .flag = 0, .val = 'n' },
        { .name = "pCroise", .has_arg = required_argument, .flag = 0, .val = 'p'},
        { .name = "tSelect", .has_arg = required_argument, .flag = 0, .val = 't'},
        { .name = "enableRecord", .has_arg = no_argument, .flag = 0, .val = 'r'}
    };
    int isUsed = 0;
    int opt = 0;
    int long_index = 0;
    while((opt = getopt_long(argc, argv, "P:i:n:p:t:r", options, &long_index)) != -1){
        switch (opt){
        case 0:
            printf("option %s", options[long_index].name);
            if(optarg)
                printf(" with arg %s", optarg);
            printf("\n");
            break;

        case 'P':
            printf("option P with value '%s'\n", optarg);
            popSize = atoi(optarg);
            isUsed = 1;
            break;

        case 'i':
            printf("option i with value '%s'\n", optarg);
            indivSize = atoi(optarg);
            isUsed = 1;
            break;

        case 'n':
            printf("option n with value '%s'\n", optarg);
            nGen = atoi(optarg);
            isUsed = 1;
            break;

        case 'p':
            printf("option p with value '%s'\n", optarg);
            pCroise = atoi(optarg);
            isUsed = 1;
            break;

        case 't':
            printf("option t with value '%s'\n", optarg);
            tSelect = atoi(optarg);
            isUsed = 1;
            break;

        case 'r':
            printf("option r\n");
            enableRecord = 1;
            isUsed = 1;
            break;
        
        default:
            printf("?? getopt returned character code 0%o ??\n", opt);
        }
    }
    return isUsed;
}

// Controls the inputs from the user
void getValuesFromUser()
{
    printf("Entez une taille pour la population :\n");
    scanf("%hi", &popSize);
    while (popSize < 0)
    {
        printf("La taille de la population doit etre positive \n");
        scanf("%hi", &popSize);
    }
    printf("Entrez une taille pour les individus :\n");
    scanf("%hi", &indivSize);
    while (indivSize < 0)
    {
        printf("La taille d'un individu doit etre positive \n");
        scanf("%hi", &indivSize);
    }
    printf("Entrez le nombre d'iterations de l'algorithme :\n");
    scanf("%hi", &nGen);
    while(nGen < 0){
        printf("Le nombre d'iterations doit etre positif \n");
        scanf("%hi", &nGen);
    }
    printf("Entrez une propabilite de croisement entre individus (entre 0 et 1):\n");
    scanf("%lf", &pCroise);
    while(pCroise > 1 || pCroise < 0){
        printf("La probabilite doit etre comprise entre 0 et 1 :\n");
        scanf("%lf", &pCroise);
    }
    printf("Entrez le nombre d'individus a garder pour la nouvelle gen : ");
    scanf("%hi", &tSelect);
    while (tSelect < 0)
    {
        printf("Le nombre d'individus doit etre positif \n");
        scanf("%hi", &tSelect);
    }
    printf("Souhaitez vous activer l'enregistrement de l'evolution de la population ? [1/0]\n");
    scanf("%hi", &enableRecord);
    while (enableRecord != 1 && enableRecord != 0)
    {
        printf("Entrez un caractere valable [1/0]\n");
        scanf("%hi", &enableRecord);
    }
}

int main(int argc, char **argv){
    srand(time(NULL));
    if (!getValuesFromArgs(argc, argv)) getValuesFromUser();
    Population *pop = initPopulation(popSize, indivSize);
    assert(pop != NULL);
    FILE *f = NULL;
    if (enableRecord)
    {
        f = fopen("../Population_Records.txt", "w");
    }
    for(short i = 0; i < nGen; i++){
        if(enableRecord){
            recordPopulationEvolution(f, pop, i);
        }
    }
    for (short i = 0; i < nGen; i++)
    {
        if (enableRecord)
        {
            recordPopulationEvolution(f, pop, i);
        }
        crossPopulation(pop, pCroise);
        quickSort(pop->individuals, 0, popSize - 1);
        selectBestOfPopulation(pop, tSelect);
    }
    if (enableRecord)
    {
        fclose(f);
    }
    freePopulation(pop);
    return EXIT_SUCCESS;
}