#include "../include/population.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printInt(void* i){
    int* val = i;
    printf("%i", *val);
}

int main(){
    LinkedList* list = createLinkedList();
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    *a = 1;
    *b = 2;
    LinkedList_Append(list, a);
    LinkedList_Append(list, b);
    LinkedList_Print(list, printInt);
    LinkedList_SwapNodes(list, 0, 1);
    LinkedList_Print(list, printInt);
    // srand(time(NULL));
    // Population* pop = initPopulation(10,8);
    // if(!pop) return EXIT_FAILURE;
    // printf("Lets go");
    // int nGen = 10;
    // for(int i = 0; i < nGen; i++){

    // }
    return EXIT_SUCCESS;
}