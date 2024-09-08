#include<stdio.h>
#include<stdlib.h>


void Shell_Sort(int *arr,int size)
{
    for(int interval = size/2;interval > 0;interval /= 2)
    {
        for(int i = interval;i < size;i++)
        {
            int temp = arr[i];
            int j = 0;
            for(j = i;j >= interval && arr[j - interval] > temp;j -= interval)
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
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
    printf("---------------------------------Shell Sort--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Shell_Sort(arr,size);
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}