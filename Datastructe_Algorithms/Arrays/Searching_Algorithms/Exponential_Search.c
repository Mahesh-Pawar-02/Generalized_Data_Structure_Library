#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Exponential_Search(int *arr,int size,int search)
{
    int high = size - 1,low = 0,m = 0,mid = 0;
    int i = 0;
    m = pow(2,i);
    if(arr[0] == search)
    {
        return 0;
    }

    while(arr[m] <= search && m < size)
    {
        i++;
        m = pow(2,i);
        while(low <= high)
        {
            mid = (low+high)/2;
            if(arr[mid] == search)
            {
                return mid;
            }
            else if(arr[mid] < search)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
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
    printf("---------------------------Exponential Search------------------------------\n");
    int size = 0,search = 0;
    int *arr = NULL;


    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the element you want to search : \n");
    scanf("%d",&search);

    int iRet = Exponential_Search(arr,size,search);   
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