// Write a program to find the total number of subset and proper subset of n element
// also specify the elements of subsets (n >8).

#include <stdio.h>
void subarring(int arr[], int n)
{
    int count = 0;
    printf("\n");
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            printf("Subset %d: ", count + 1);
            for (int k = i; k <= j; k++)
            {
                printf("%d ", arr[k]);
            }

            printf("\n");
            count++;
        }
    }
    printf("\nTotal number of subsets are: %d\n", count);
    printf("Total number of proper subsets are: %d\n", count - 1);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    subarring(arr, n);
    return 0;
}
