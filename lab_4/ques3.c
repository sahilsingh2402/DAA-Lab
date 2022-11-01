// For a given array find the largest palindrome subarray.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s)
{
    int n = strlen(s), begin = 0, longest = 1;
    int dp[n][n];
    memset(dp, 0, n * n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int length = 2; length <= n; length++)
    {
        for (int start = 0; start < n; start++)
        {
            int end = start + length - 1;
            if (end >= n)
            {
                break;
            }

            if (s[start] != s[end])
            {
                dp[start][end] = 0;
            }
            else
            {
                if (length <= 2)
                {
                    dp[start][end] = 1;
                }
                else
                {
                    dp[start][end] = dp[start + 1][end - 1];
                }
            }
            if (dp[start][end])
            {
                if (length > longest)
                {
                    longest = length;
                    begin = start;
                }
            }
        }
    }
    char *result = malloc(n + 1);
    strncpy(result, s + begin, longest);
    result[longest] = 0;

    return result;
}

int main()
{
    char arr[] = {'a', 'b', 'a', 'b', 'a', 'd'};
    unsigned int n = sizeof(arr) / sizeof(arr[0]);
    char *ans;
    ans = longestPalindrome(arr);
    unsigned int m = sizeof(ans) / sizeof(ans[0]);
    printf("%s\n", ans);
    return 0;
}