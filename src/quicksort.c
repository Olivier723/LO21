#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>

void swap(Individual** list,int a, int b){
    Individual* temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

int partition(Individual** list, int start, int end){
    double pivot = getIndividualQuality(list[end]);
    int pivotIndex = start;
    for(int i = start; i < end; i++){
        if(getIndividualQuality(list[i]) < pivot){
            swap(list, i, pivotIndex);
            pivotIndex++;
        }
    }
    swap(list, pivotIndex, end);
    return pivotIndex;
}

Individual** quickSort(Individual** list, int start, int end){
    if(start >= end) return list;
    int index = partition(list,start,end);
    quickSort(list,start,index-1);
    quickSort(list,index+1,end);
}