#include<stdio.h>

int main(void)
{
    int n, x, result;
    int arr[10];
    printf("\nEnter the no of elements in array:" );
    scanf("%d",&n);
    printf("\nEnter the elements of array:");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the elements to be searched in array:");
    scanf("%d", &x);
    result = search( arr , n , x );
    (result==-1)?printf("\nElement not found.") : printf("\nElement found at index:%d",result);
    
}

int search(int arr[], int n, int x){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==x){
            return i+1;
        }
    }
    return -1;
};
