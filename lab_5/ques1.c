// write a program for merge sort (ascending order), plot the graph
// a) using a series of random number (500, 1000, 5000, 10000)
// b) using a series of ascending order (500, 1000, 5000, 10000)
// c) using a series of descending order (500, 1000, 5000, 10000)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
clock_t start, end;
double cpu_time;

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there  are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void generateRandomArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = rand() % size;
}

void generateAscendingArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = i;
}

void generateDescendingArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = size - i;
}

int main()
{
    int arr[10000];
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("\n");
    printf("Enter 1 for random array, 2 for ascending array, 3 for descending array: ");
    int choice;
    scanf("%d", &choice);
    printf("\n");

    start = clock();
    switch (choice)
    {
    case 1:
        generateRandomArray(arr, size);
        break;
    case 2:
        generateAscendingArray(arr, size);
        break;
    case 3:
        generateDescendingArray(arr, size);
        break;
    default:
        printf("Invalid choice\n");
        return 0;
    }
    end = clock();

    printf("\n");
    printf("Unsorted array: \n");
    printArray(arr, size);
    printf("\n");
    mergeSort(arr, 0, size - 1);
    printf("\n");
    printf("Sorted array: \n");
    printArray(arr, size);
    printf("\n");

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time);
    return 0;
}