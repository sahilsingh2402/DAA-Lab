// Write a program to compare the time of execution of linear search and binary search

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start, end;
double cpu_time;

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int start, int end, int search)
{
    int mid;
    if (end >= start)
    {
        mid = (start + end) / 2;
        /* if the item to be searched is present at middle */
        if (arr[mid] == search)
        {
            return mid + 1;
        }
        /* if the item to be searched is smaller than middle, then it can only be in left subarray */
        else if (arr[mid] < search)
        {
            return binarySearch(arr, mid + 1, end, search);
        }
        /* if the item to be searched is greater than middle, then it can only be in right subarray */
        else if (arr[mid] > search)
        {
            return binarySearch(arr, start, mid - 1, search);
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    start = clock();
    int n, search;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &search);

    printf("\n\n---Using Linear Search---\n");
    int result = linearSearch(arr, n, search);
    if (result == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at index %d", result);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time);

    printf("\n\n---Using Binary Search---\n");
    start = clock();
    int result1 = binarySearch(arr, 0, n - 1, search);
    if (result1 == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at index %d", result1 - 1);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time);

    return 0;
}
