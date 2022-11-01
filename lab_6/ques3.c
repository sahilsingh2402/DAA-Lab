// write a program to implement activity selection problem

#include <stdio.h>
struct activity
{
    int start, finish;
};
void sort(struct activity A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j].finish > A[j + 1].finish)
            {
                struct activity temp;
                 A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
void input(struct activity A[], int n)
{
    printf("Enter start and finish times of each activity:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &A[i].start, &A[i].finish);
    }
}

void solve(struct activity *A, int n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i].start >= t)
        {
            printf("Activity %d\n", i);
            t = A[i].finish;
        }
    }
}

int main()
{
    printf("Enter number of activities: ");
    int n;
    scanf("%d", &n);
    struct activity A[n];
    input(A, n);
    sort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i].start);
        printf("%d  \n", A[i].finish);
    }
    solve(A, n);
}