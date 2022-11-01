// Find the sum of a contiguous subarray within a 1 – D array of numbers () which has the largest sum.

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int currSum = 0, maxSum = -9999;
    for (int i = 0; i < n; i++)
    {
        currSum = currSum + arr[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
    }

    printf("Maximum Contagious Sum: %d\n", maxSum);
    return 0;
}