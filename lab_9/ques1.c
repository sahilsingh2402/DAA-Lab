// WAP to implement LCS using dynamic programming

#include <stdio.h>
#include <string.h>

int i, j, m, n, dp[20][20];
char S1[20] = "ACADB", S2[20] = "CBDA", b[20][20];

void lcsAlgo()
{
    m = strlen(S1);
    n = strlen(S2);

    for (i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (i = 0; i <= n; i++)
        dp[0][i] = 0;

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }

    int idx = dp[m][n];
    char lcsAlgo[idx + 1];
    lcsAlgo[idx] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcsAlgo[idx - 1] = S1[i - 1];
            i--;
            j--;
            idx--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("S1 : %s \nS2 : %s \n", S1, S2);
    printf("LCS: %s", lcsAlgo);
}

int main()
{
    lcsAlgo();
    printf("\n");
}