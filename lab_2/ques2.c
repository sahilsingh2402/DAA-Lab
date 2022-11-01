// Write a program to add n number of Matrices, n will be user input n >= 3

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, mat_count, m1[10][10], m2[10][10], sum[10][10];

    printf("Enter the number of marices: ");
    scanf("%d", &mat_count);
    printf("Enter the number of rows and columns of matrix\n");
    scanf("%d%d", &m, &n);

    printf("Enter the elements of 1 matrix\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter the elements of 2 matrix\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i][j] = m1[i][j] + m2[i][j];
            // printf("%d\t", sum[c][d]);
        }
    }
    mat_count -= 2;
    int i = 3;
    while (mat_count--)
    {
        printf("Enter the elements of %d matrix: \n", i);
        i++;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &m1[i][j]);
                sum[i][j] += m1[i][j];
            }
    }
    printf("The sum of all matrices is: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}