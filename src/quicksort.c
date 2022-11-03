#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>

void swap(LinkedList* list,int a, int b){
    /*
    Le problème est là; je pense que la fonction remove et la fonction insert n'opèrent pas sur le meme indice
    */
    Individual* temp = LinkedList_Get(list, a);
    Individual* temp2 = LinkedList_Get(list, b);
    LinkedList_Remove(list, a);
    LinkedList_Insert(list, temp2, a-1);
    LinkedList_Remove(list, b);
    LinkedList_Insert(list, temp, b-1);
}

int partition(LinkedList* list, int start, int end){
    Individual* pivotIndiv = LinkedList_Get(list, end);
    printf("%i", pivotIndiv->longIndiv);
    double pivot = getIndividualQuality(pivotIndiv);
    int pivotIndex = start;
    for(int i = start; i < end; i++){
        Individual* tempIndiv = LinkedList_Get(list, i);
        if(getIndividualQuality(tempIndiv) < pivot){
            swap(list, i, pivotIndex);
            pivotIndex++;
        }
    }
    swap(list, pivotIndex, end);
    return pivotIndex;
}

void quickSort(LinkedList* list, int start, int end){
    if(start >= end) return ;
    printf("%i,%i\n",start,end);
    int index = partition(list,start,end);
    quickSort(list,start,index-1);
    quickSort(list,index+1,end);
}