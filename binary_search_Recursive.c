#include<stdio.h>

int binarySearch(int arr[], int left, int right, int no) 
{
    while(left<=right)
    {
        int mid = (left+ right)/2;
        if (arr[mid] == no)
            return mid;
        else if (arr[mid]>no)
            return  binarySearch(arr, left, mid-1, no);
        else
            return binarySearch(arr, mid+1,right, no);
    }
    return -1;
}

int main() 
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int no;
    printf("Enter number to search: ");
    scanf("%d", &no);
    int result = binarySearch(arr, 0,size-1, no);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}
