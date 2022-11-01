// WAP to multiply two numbers using recursion (using addition operator).

#include <stdio.h>
int product(int a, int b)
{
    if (a < b)
    {
        return product(b, a);
    }
    else if (b != 0)
    {
        return (a + product(a, b - 1));
    }
    else
    {
        return 0;
    }
}

int main()
{
    int a, b, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    result = product(a, b);
    printf("Product of %d and %d = %d\n", a, b, result);
    return 0;
}