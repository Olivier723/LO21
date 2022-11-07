#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>

int partition(LinkedList *list, int start, int end)
{
    Individual *pivotIndiv = LinkedList_Get(list, end);
    double pivot = getIndividualQuality(pivotIndiv);
    int pivotIndex = start;
    for (int i = start; i < end; i++)
    {
        Individual *tempIndiv = LinkedList_Get(list, i);
        if (getIndividualQuality(tempIndiv) < pivot)
        {
            // printf("Swap1 test\n");
            LinkedList_Swap(list, i, pivotIndex);
            // printf("Swap1 pass\n");
            pivotIndex++;
        }
    }
    // printf("Swap2 test\n");
    LinkedList_Swap(list, pivotIndex, end);
    // printf("Swap2 pass\n");
    return pivotIndex;
}

void quickSort(LinkedList *list, int start, int end)
{
    // printf("%i-%i\n", start, end);
    if (start >= end)
        return;
    int index = partition(list, start, end);
    quickSort(list, start, index - 1);
    quickSort(list, index + 1, end);
}