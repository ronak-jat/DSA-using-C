#include<stdio.h>

int binarySearch(int arr[], int size, int no) 
{
    int left = 0 , right = size-1;
    
    while(left<=right)
    {
        int mid = (left+ right)/2;
        if (arr[mid] == no)
            return mid;
        else if (arr[mid]>no)
            right = mid-1;
        else
            left = mid+1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int no;
    printf("Enter number to search: ");
    scanf("%d", &no);
    int result = binarySearch(arr, size, no);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}

