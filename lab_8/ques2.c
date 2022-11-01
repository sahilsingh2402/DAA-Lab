// WAP to print multiplication table of any number (n) using n.

#include <stdio.h>
void mul_table(int n, int i)
{
    if (i > 10)
    {
        return;
    }
    printf("%d x %d = %d\n", n, i, n * i);
    return mul_table(n, i + 1);
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    mul_table(n, 1);
    return 0;
}