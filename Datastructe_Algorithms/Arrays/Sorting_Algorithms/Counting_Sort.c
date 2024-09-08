#include<stdio.h>
#include<stdlib.h>

void Counting_Sort(int *arr, int size)
{
    int max = arr[0];
    int i = 0,index = 0;

    for(i = 1; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
  
    int count[max + 1];

    for(i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for(i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    for(i = 0; i <= max; i++) 
    {
        while(count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
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
    printf("---------------------------------Counting Sort--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Counting_Sort(arr,size);
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}