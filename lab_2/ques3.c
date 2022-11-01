// write a program to add two large integer wihtout using long datatype.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int len1, len2, i, j, carry = 0, sum = 0;
    printf("Enter the first number: ");
    scanf("%s", str1);
    printf("Enter the second number: ");
    scanf("%s", str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    if (len1 > len2)
    {
        for (i = len1 - 1; i >= len2; i--)
        {
            str1[i] = '0';
        }
    }
    else
    {
        for (i = len2 - 1; i >= len1; i--)
        {
            str2[i] = '0';
        }
    }

    for (i = len1 - 1; i >= 0; i--)
    {
        sum = (str1[i] - '0') + (str2[i] - '0') + carry;
        str1[i] = sum % 10 + '0';
        carry = sum / 10;
    }
    if (carry)
    {
        str1[i] = carry + '0';
    }
    printf("The sum of two numbers is: %s\n", str1);

    return 0;
}