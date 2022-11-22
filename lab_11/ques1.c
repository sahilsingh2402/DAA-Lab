// WAP to implement floyd warshall algorithm

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[10][10], p[10][10], i, j, k, n;
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("Enter the cost matrix: ");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                a[i][j] = 999;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            p[i][j] = 0;
        }
    }
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
    printf("The shortest path matrix is: ");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d", a[i][j]);
        }
        printf(" ");
        for (j = 1; j <= n; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Output:

// Enter the number of vertices:4
// Enter the cost matrix: 0 3 8 999
// -2 0 999 1
// 999 4 0 999
// 6 999 7 0
