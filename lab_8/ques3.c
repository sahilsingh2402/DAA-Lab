// WAP to implement Matrix Chain Multiplication using dynamic program must show the calculation table.

#include <stdio.h>
int mcm()
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int k = j + i;
            dp[j][k] = 999999;
            for (int l = j; l < k; l++)
            {
                int temp = dp[j][l] + dp[l + 1][k] + arr[j] * arr[l + 1] * arr[k + 1];
                if (temp < dp[j][k])
                {
                    dp[j][k] = temp;
                }
            }
        }
    }
    printf("The minimum number of multiplications required is: %d\n", dp[0][n - 1]);
    return 0;
}