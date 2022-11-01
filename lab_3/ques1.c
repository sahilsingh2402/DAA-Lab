// Find the GCD and LCM of n numbers where (n>=2).

#include <stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);
        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int ans = a[0];
    for (int i = 1; i < n; i++)
    {
        ans = (((a[i] * ans)) / (gcd(a[i], ans)));
    }
    printf("LCM: %d\n", ans);
    int gcd = findGCD(a, n);
    printf("GCD: %d\n", gcd);
    return 0;
}
