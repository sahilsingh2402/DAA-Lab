// Find the sum of a contiguous subarray within a 1 – D array of positive numbers which has the largest sum.

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], sum = 0;
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Largest Sum: %d\n", sum);
    return 0;
}
