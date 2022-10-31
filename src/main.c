#include "../include/population.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Population* pop = initPopulation(10,10);
    if(!pop) return EXIT_FAILURE;
    printf("Lets go");
    int nGen = 10;
    for(int i = 0; i < nGen; i++){

    }
    return EXIT_SUCCESS;
}