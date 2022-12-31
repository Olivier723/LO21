#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>

int partition(LinkedList *list, int start, int end)
{
    Individual *pivotIndiv = LinkedList_Get(list, end);
    double pivot = getIndividualQuality2(pivotIndiv);
    int pivotIndex = start;
    for (int i = start; i < end; i++)
    {
        Individual *tempIndiv = LinkedList_Get(list, i);
        if (getIndividualQuality2(tempIndiv) > pivot)
        {
            LinkedList_Swap(list, i, pivotIndex);
            pivotIndex++;
        }
    }
    LinkedList_Swap(list, pivotIndex, end);
    return pivotIndex;
}

void quickSort(LinkedList *list, int start, int end)
{
    if (start >= end)
        return;
    int index = partition(list, start, end);
    quickSort(list, start, index - 1);
    quickSort(list, index + 1, end);
}