#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_SortR(int *arr,int size)
{
    bool swapped = false;

    for(int i = 0;i < size - 1;i++)
    {
        if(arr[i] > arr[i + 1])
        {
            swap(&arr[i],&arr[i + 1]);
            swapped = true;
        }
    }
    if(swapped == false)
    {   
        return;
    }

    Bubble_SortR(arr,size - 1);
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
    printf("---------------------------Bubble Sort using Recursion------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Bubble_SortR(arr,size);   
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}