#include "../include/quicksort.h"
#include <stdlib.h>
#include <stdio.h>

void swap(LinkedList *list, int a, int b)
{
    Individual *temp = LinkedList_Get(list, a);
    Individual *temp2 = LinkedList_Get(list, b);
    LinkedList_Remove(list, a);
    LinkedList_Insert(list, temp2, a);
    LinkedList_Remove(list, b);
    LinkedList_Insert(list, temp, b);
}

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
            LinkedList_SwapNodes(list, i, pivotIndex);
            pivotIndex++;
        }
    }
    LinkedList_SwapNodes(list, pivotIndex, end);
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