#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr,int low,int high)
{
    int pivot = arr[high];

    int i = (low - 1);

    for(int j = low;j <= high - 1;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i + 1],&arr[high]);
    return (i + 1);
}

void Quick_Sort(int *arr,int low,int high)
{
    while(low < high)
    {
        int pivot = partition(arr,low,high);

        if(pivot - low < high - pivot)
        {
            Quick_Sort(arr,low,pivot - 1);
            low = pivot + 1;
        }
        else
        {
            Quick_Sort(arr,pivot + 1,high);
            high = pivot - 1;
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
    printf("---------------------------------Quick Sort using Tail Call Elimination--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Quick_Sort(arr,size);
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}