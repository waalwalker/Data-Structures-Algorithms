# include<stdio.h>

int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return i;
        }
        printf("The element %d not found in the array.\n", element);
        return -1;  
    } 
}

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Search Starting point:
    while (low<=high)
    {
        mid = (low+high) / 2;
        if (arr[mid]==element)
        {
            return mid;
        }
        if (arr[mid]<element)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }   
    }
    // Search Ending point

    printf("The element %d not found in the array.\n", element);
    return -1;
}

int main(){
    // int arr[] = {1, 4, 5, 6,4,45,28,99,7,48,87}; Unsorted Array for linear Search
    int arr[] = {100,200,300,444,555,666,800,999};
    int size = sizeof(arr)/sizeof(int);
    int element = 999;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d. \n", element, searchIndex);
    return 0;
}