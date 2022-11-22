// write a c program to generate 1000 random numbers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start, end;
double cpu_time;

int main()
{
    start = clock();
    int i;
    for (i = 0; i < 1000; i++)
    {
        printf("%d ", rand() % 100);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time);
    return 0;
}

// Explain the functioning of above code step by step.

// It is a program to generate 1000 random numbers between 0 and 99.

