// write a c program for maximum sum of two numbers in an array

#include <stdio.h>
#include <time.h>
clock_t start, end;
double cpu_time;
int main()
{
    start = clock();
    int n = 0, i = 0, max1 = 0, max2 = 0, temp = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    max1 = array[0];
    max2 = array[1];

    if (max1 < max2)
    {
        temp = max1;
        max1 = max2;
        max2 = temp;
    }

    for (int i = 2; i < n; i++)
    {
        if (array[i] > max1)
        {
            max2 = max1;
            max1 = array[i];
        }
        else if (array[i] > max2 && array[i] != max1)
        {
            max2 = array[i];
        }
    }

    printf("Max 1 Element: %d\n", max1);
    printf("Max 2 Element: %d\n", max2);
    printf("\nMaximum sum of two elements in the array: %d", max1 + max2);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time);

    return 0;
}