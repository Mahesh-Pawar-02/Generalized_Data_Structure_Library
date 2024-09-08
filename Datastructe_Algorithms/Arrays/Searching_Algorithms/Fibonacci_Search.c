#include<stdio.h>
#include<stdlib.h>


int min(int a,int b)
{
    return (a < b) ? a : b;
}

int Fibonacci_Search(int *arr,int size,int search)
{
    int offset = -1;
    int Fm1 = 1;
    int Fm2 = 0;
    int Fm = Fm1 + Fm2;
    while(Fm < size)
    {
        Fm2 = Fm1;
        Fm1 = Fm;
        Fm = Fm2 + Fm1;
    }

    while(Fm > 1)
    {
        int i = min(offset+Fm2,size-1);
        
        if(arr[i] < search)
        {
            Fm = Fm1;
            Fm1 = Fm2;
            Fm2 = Fm - Fm1;
            offset = i;
        }
        else if(arr[i] > search)
        {
            Fm = Fm2;
            Fm1 = Fm1 - Fm2;
            Fm2 = Fm - Fm1;
        }
        else
        {
            return i;
        }
    }

    if(Fm && arr[offset + 1] == search)
    {
        return offset+1;
    }
    else
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
    printf("---------------------------Fibonacci Search------------------------------\n");
    int size = 0,search = 0;
    int *arr = NULL;


    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the element you want to search : \n");
    scanf("%d",&search);

    int iRet = Fibonacci_Search(arr,size,search);
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