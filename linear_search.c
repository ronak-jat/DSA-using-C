#include<stdio.h>

int linearSearch(int arr[], int size, int no)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == no) 
            return i; 
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
    int result = linearSearch(arr, size, no);
    if (result != -1) 
    {
        printf("Element found at index %d\n", result);
    }
    else{
        printf("Element not found in the array.\n");
    }
    return 0;
}
