#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr,int size,int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,size,largest);
    }
}

void Heap_SortR(int *arr,int size)
{
    for(int i = size/2-1;i >= 0;i--)
    {
        heapify(arr,size,i);
    }

    for(int i = size - 1;i >= 0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
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
    printf("---------------------------------Heap Sort using recursion--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Heap_SortR(arr,size);
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}