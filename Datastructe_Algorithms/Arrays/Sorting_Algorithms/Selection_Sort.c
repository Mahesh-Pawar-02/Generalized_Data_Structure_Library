#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Selection_Sort(int *arr,int size)
{
    int i = 0,j = 0,min_index = 0;

    for(i = 0;i < size - 1;i++)
    {
        min_index = i;
        for(j = i + 1;j < size;j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if(min_index != i)
        {
            swap(&arr[min_index],&arr[i]);
        }
        
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
    printf("---------------------------------Selection Sort--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Selection_Sort(arr,size);   
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}