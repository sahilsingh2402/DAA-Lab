// Suppose you have to give Rs N to your friend. Assume that you have enough number of 500, 200, 100, 50, 20, 10 rupee notes each at your disposal. Your goal is to give Rs N to your friend with minimum number of notes. For example, you can give Rs 600 can be given using 3 Rs 200 notes as well as using 1 Rs 500 note and 1 Rs 100 note. However, since the latter one uses minimum number of notes, so it will be the chosen solution.

// • Now, either prove the correctness or provide counter example of the following greedy strategy: keep picking highest denomination as much as you can!

// • Provide a set of denominations for which the above greedy strategy will fail.

// • Now, design an efficient algorithm for the above problem. Find the time complexity also.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int count = 0;
    while (n > 0)
    {
        if (n >= 500)
        {
            n -= 500;
            count++;
            printf("Re 500 Note\n");
        }
        else if (n >= 200)
        {
            n -= 200;
            count++;
            printf("Re 200 Note\n");
        }
        else if (n >= 100)
        {
            n -= 100;
            count++;
            printf("Re 100 Note\n");
        }
        else if (n >= 50)
        {
            n -= 50;
            count++;
            printf("Re 50 Note\n");
        }
        else if (n >= 20)
        {
            n -= 20;
            count++;
            printf("Re 20 Note\n");
        }
        else if (n >= 10)
        {
            n -= 10;
            count++;
            printf("Re 10 Note\n");
        }
    }
    printf("Total Number of Notes: %d\n", count);
    return 0;
}

// Time Complexity: O(n)
