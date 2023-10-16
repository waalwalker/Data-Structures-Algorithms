#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
void countSort(int *A, int n)
{
    int i, j;
    // Find the maximum element in the A
    int max = maximum(A, n);

    // Create the Count Array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Initialize the array elements to 0
    for (i = 0; i < (max + 1); i++)
    {
        count[i] = 0;
    }

    // Increment the index of the corresponding index in the count Array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }
    i = 0; // count for count array
    j = 0; // count for given array

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {3, 7, 12, 99, 27, 8};
    int n = 6;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n);
    return 0;
}