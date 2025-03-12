#include<stdio.h>

int linearSearch_r(int arr[], int size, int no)
{
    if (size<=0)  return -1;
    if (no == arr[size-1]) return size-1;
    return linearSearch_r(arr, size-1, no);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int no;
    printf("Enter number to search: ");
    scanf("%d", &no);
    int result = linearSearch_r(arr, size, no);
    if (result != -1) 
    {
        printf("Element found at index %d\n", result);
    }
    else{
        printf("Element not found in the array.\n");
    }
    return 0;
}
