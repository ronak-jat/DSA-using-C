#include<stdio.h>

int delete(int arr[],int n,int pos)
{
    if (n <= 0)
    {
        printf("underflow condition");
    }
    for (int i = pos ; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    return n-1;
}

void display(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {1, 2, 4, 5, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    int pos = 2;
    n = delete(arr, n, pos);
    printf("Updated Array: ");
    display(arr,n);
    return 0;
}
