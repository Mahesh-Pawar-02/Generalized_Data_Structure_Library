#include<stdio.h>
#include<stdlib.h>

int Linear_Search(int *arr,int size,int search)
{
    int i = 0;
    for(i = 0;i < size;i++)
    {
        if(arr[i] == search)
        {
            return i;
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
    printf("------------------Linear Search--------------------\n");

    int size = 0,search = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the element you want to search : \n");
    scanf("%d",&search);

    int iRet = Linear_Search(arr,size,search);
    if(iRet >= 0)
    {
        printf("Element found at index : %d\n",iRet);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("---------------------------------------------------\n");


    return 0;
}