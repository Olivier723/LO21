#include "../include/population.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Population* pop = initPopulation(10,10);
    if(!pop) return EXIT_FAILURE;
    printf("%i",pop->size);
    return EXIT_SUCCESS;
}