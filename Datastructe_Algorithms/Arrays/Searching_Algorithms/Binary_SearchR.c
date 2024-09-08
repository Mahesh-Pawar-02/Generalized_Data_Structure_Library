#include<stdio.h>
#include<stdlib.h>

int Binary_SearchR(int *arr,int low,int high,int search)
{
    
    if(low <= high)
    {
        int mid = (low + high)/2;

        if(arr[mid] == search)
        {
            return mid;
        }
        else if(arr[low] == search)
        {
            return low;
        }
        else if(arr[high] == search)
        {
            return high;
        }
        else if(search < arr[mid])
        {
            high = Binary_SearchR(arr,low,mid-1,search);
        }
        else
        {
            low = Binary_SearchR(arr,mid + 1,high,search);
        }
    }

    if(low >= high)
    {
        return -1;
    }
}

void Accept(int *arr,int size)
{
    int i = 0;
    printf("Enter the elements of array : \n");
    for(i = 0;i < size;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void Display(int *arr,int size)
{
    int i = 0;
    printf("Elements of array are : \n");
    for(i = 0;i < size;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("------------------Binary Search using recursion--------------------\n");

    int size = 0,search = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the element you want to search : \n");
    scanf("%d",&search);

    int iRet = Binary_SearchR(arr,0,size - 1,search);   
    if(iRet >= 0)
    {
        printf("Element found at index : %d\n",iRet);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("-------------------------------------------------------------------\n");


    return 0;
}