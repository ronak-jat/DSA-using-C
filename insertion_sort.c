#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while(j>0 && arr[j] < arr[j-1])
        {
            int temp = arr[j];
            arr[j] = arr[j-1]; 
            arr[j-1] = temp;
            j--;
        }
    }
}
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printf("Sorted Array: ");
    printArray(arr, n);
    return 0;
}
