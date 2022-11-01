// write a c program for selection sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start, end;
double cpu_time;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}
int main()
{
    start = clock();
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter %d elements in ascending order: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time);

    start = clock();
    int arr1[n];
    printf("\nEnter %d elements in descending order: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    selectionSort(arr1, n);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time);

    start = clock();
    int arr2[1000];
    printf("\nEntering 1000 random elements: ");
    for (i = 0; i < 1000; i++)
    {
        arr2[i] = rand() % 100;
    }
    selectionSort(arr2, 1000);
    printf("\nSorted array: ");
    for (i = 0; i < 1000; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time);
    return 0;
}