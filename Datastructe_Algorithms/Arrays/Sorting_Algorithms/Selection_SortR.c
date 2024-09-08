#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Selection_SortR1(int *arr, int i, int j, int size, int flag)
{
    int temp;
 
    if (i < size - 1)
    {
        if (flag)
        {
            j = i + 1;
        }
        if (j < size)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            Selection_SortR1(arr, i, j + 1, size, 0);
        }
        Selection_SortR1(arr, i + 1, 0, size, 1);
    }
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minIndex(int *arr,int i,int j)
{
    if(i == j)
    {
        return i;
    }

    int k = minIndex(arr,i + 1,j);

    return (arr[i] < arr[k]) ? i : k;
}

void Selection_SortR(int *arr,int size,int index)
{
    if(index == size)
    {
        return;
    }

    int k = minIndex(arr,index,size - 1);

    if(k != index)
    {
        swap(&arr[k],&arr[index]);
    }

    Selection_SortR(arr,size,index+1);
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
    printf("---------------------------------Selection Sort using recursion--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Selection_SortR(arr,size,0);   
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}