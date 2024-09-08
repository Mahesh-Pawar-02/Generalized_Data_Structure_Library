#include<stdio.h>
#include<stdlib.h>

int Interpolation_SearchR(int *arr,int size,int search,int low,int high)
{
    
    while(low <= high &&  search >= arr[low] && search <= arr[high])
    {
        if(low == high)
        {
            if(arr[high] == search)
            {
                return high;
            }
            else
            {
                return -1;
            }
        }

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (search - arr[low]));

        if(arr[pos] == search)
        {
            return pos;
        }
        else if(arr[pos] < search)
        {
            high = Interpolation_SearchR(arr,size,search,low,pos-1);
        }
        else
        {
            low = Interpolation_SearchR(arr,size,search,pos + 1,high);
        }

    }

    return -1;
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
    printf("---------------------------Interpolation Search using Recursion------------------------------\n");
    int size = 0,search = 0;
    int *arr = NULL;


    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the element you want to search : \n");
    scanf("%d",&search);

    int iRet = Interpolation_SearchR(arr,size,search,0,size - 1);   
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