// write a c program for bubble sort

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
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
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
    bubbleSort(arr, n);
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
    printf("\n\nEnter %d elements in descending order: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    bubbleSort(arr1, n);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time);

    int arr2[1000];
    printf("\n\nEntering 1000 random elements: ");
    for (i = 0; i < 1000; i++)
    {
        arr2[i] = rand() % 100;
    }
    bubbleSort(arr2, 1000);
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
