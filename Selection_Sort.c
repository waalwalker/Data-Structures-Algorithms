# include<stdio.h>

void printArray(int* A, int n){
    printf("The Array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int*A, int n){
    int indexOfMin, temp;
    printf("Running Selection Sort....\n");
    printf("Array after Insertion Sorting: \n");
    for (int i = 0; i < n-1; i++)
    {
        int indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // Swapping A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main(){
    int A[] = {3, 7, 12, 99, 27, 8};
    int n = 6;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    return 0;
}