#include<stdio.h>
#include<stdlib.h>

void Insertion_SortR(int *arr,int size,int i)
{
    if(i == size)
    {
        return;
    }

    int j = i;

    while(j > 0 && arr[j - 1] > arr[j])
    {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }
    
    Insertion_SortR(arr,size,i + 1);
    
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
    printf("---------------------------------Insertion Sort using recursion--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Insertion_SortR(arr,size,0);   
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}