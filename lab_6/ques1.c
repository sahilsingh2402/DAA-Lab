// Write a program to Count the number of ways we can parenthesize the expression so that the value of expression
// evaluates to 1. Symbols are 0 and 1, Operators are logical AND(&) and OR(|).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countParenth(char symb[], char oper[], int n)
{
    int F[n][n], T[n][n];
    for (int i = 0; i < n; i++)
    {
        F[i][i] = (symb[i] == '0') ? 1 : 0;
        T[i][i] = (symb[i] == '1') ? 1 : 0;
    }

    for (int gap = 1; gap < n; ++gap)
    {
        for (int i = 0, j = gap;
             j < n; ++i, ++j)
        {
            T[i][j] = F[i][j] = 0;
            for (int g = 0;
                 g < gap; g++)
            {
                int k = i + g;
                int tik = T[i][k] + F[i][k];
                int tkj = T[k + 1][j] + F[k + 1][j];
                if (oper[k] == '&')
                {
                    T[i][j] += T[i][k] * T[k + 1][j];
                    F[i][j] += (tik * tkj - T[i][k] * T[k + 1][j]);
                }
                if (oper[k] == '|')
                {
                    F[i][j] += F[i][k] * F[k + 1][j];
                    T[i][j] += (tik * tkj - F[i][k] * F[k + 1][j]);
                }
                if (oper[k] == '^')
                {
                    T[i][j] += F[i][k] * T[k + 1][j] + T[i][k] * F[k + 1][j];
                    F[i][j] += T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j];
                }
            }
        }
    }
    return T[0][n - 1];
}

int main()
{
    char symbols[] = "101";
    char operators[] = "^&";
    int n = strlen(symbols);

    printf("%d\n", countParenth(symbols, operators, n));
    return 0;
}
