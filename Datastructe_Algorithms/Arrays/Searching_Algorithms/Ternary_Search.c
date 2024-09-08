#include<stdio.h>
#include<stdlib.h>

int Ternary_Search(int *arr,int size,int search)
{    

    int low = 0,high = size - 1;

    while(low <= high)
    {
        int mid1 = low + (high - low)/3;
        int mid2 = high - (high - low)/3;


        if(arr[mid1] == search)
        {
            return mid1;
        }
        if(arr[mid2] == search)
        {
            return mid2;
        }
        else if(arr[low] == search)
        {
            return low;
        }
        else if(arr[high] == search)
        {
            return high;
        }
        else if(search < arr[mid1])
        {
            high = mid1 - 1;
        }
        else if(search > arr[mid2])
        {
            low = mid2 + 1;
        }
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
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
    printf("------------------Ternary Search-------------------------------------\n");

    int size = 0,search = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the element you want to search : \n");
    scanf("%d",&search);

    int iRet = Ternary_Search(arr,size,search);
    if(iRet >= 0)
    {
        printf("Element found at index : %d\n",iRet);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("----------------------------------------------------------------------\n");


    return 0;
}