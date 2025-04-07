#include<stdio.h>

int insert(int arr[],int n,int size,int pos,int value)
{
    if (n>size){
        printf("overflow condition");
        return n;
    }
    for (int i = n ; i>pos; i--){
        arr[i]=arr[i-1];;
    }
    arr[pos]=value;
    return n+1;
}

void display(int arr[], int n)
{  
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
int arr[] = {1, 2, 4, 5, 6}; 
int size = 10;
int n = sizeof(arr)/sizeof(arr[0]);
int pos = 2, value = 3; 
n = insert(arr, n, size, pos, value);
printf("Updated Array: ");
display(arr,n);
return 0;
}
