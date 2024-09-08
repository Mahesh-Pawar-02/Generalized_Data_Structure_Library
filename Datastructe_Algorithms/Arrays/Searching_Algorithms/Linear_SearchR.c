#include<stdio.h>
#include<stdlib.h>

int Linear_Search(int *arr,int size,int search)        //reverse traversal
{
    if(size == -1)
    {
        return size;
    }

    if(arr[size] == search)
    {
        return size;
    }

    size = Linear_Search(arr,size-1,search);
}

int Linear_SearchR(int *arr,int size,int search)       //forward traversal
{
    static int i = 0;
    if(i >= size)
    {
        return -1;
    }
    if(arr[i] == search)
    {
        return i;
    }
    i++;
    i = Linear_SearchR(arr,size,search);
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
    printf("------------------Linear Search using recursion--------------------\n");

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

    printf("-------------------------------------------------------------------\n");


    return 0;
}