# include<stdio.h>

void printArray(int* A, int n){
    printf("The Array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high){
    int partitionIndex; //index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        printArray(A, 6);
        quickSort(A, low, partitionIndex - 1); //sort left subarray
        quickSort(A, partitionIndex + 1, high); //sort right subarray
    }
    
}

int main(){
    int A[] = {3, 7, 12, 99, 27, 8};
    int n = 6;
    printArray(A, n);
    quickSort(A, 0, n-1);
    printArray(A, n);
    return 0;
}