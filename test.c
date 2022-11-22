// Suppose you are evaluating the marks for a course DAA. You are provided with the mid-semester and end-semester marks for all the N students in the course. A student P is said to dominate a student Q, if the mid-semester and end-semester marks of the student P are both greater than the respective mid-semester and end-semester marks of student Q. You have to design an efficient algorithm for finding all the students that are not dominated by any other student in the class. Find the time complexity also.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    int mid_marks[n];
    int end_marks[n];
    int i, j;
    int temp[n];
    printf("Enter Midsem Marks: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &mid_marks[i]);
        temp[i] = 0;
    }
    printf("Enter Endsem Marks: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &end_marks[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (temp[j] == 0 && i != j)
            {
                if (mid_marks[i] > mid_marks[j] && end_marks[i] > end_marks[j])
                {
                    temp[j] = 1;
                }
            }
        }
    }
    printf("Non dominated are\n");
    for (i = 0; i < n; i++)
    {
        if (temp[i] == 0)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
    return 0;
}
