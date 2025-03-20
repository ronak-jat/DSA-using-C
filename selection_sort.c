#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int min=i;
        for (int j = i+1; j < n ; j++) 
        {
            if (arr[min] > arr[j])
            {
                min=j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min]; 
        arr[min] = temp;
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
    selectionSort(arr, n);
    printf("Sorted Array: ");
    printArray(arr, n);
    return 0;
}
