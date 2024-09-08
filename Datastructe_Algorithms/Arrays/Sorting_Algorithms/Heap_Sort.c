#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void buildMaxHeap(int *arr,int size)
{
    for(int i = 1;i < size;i++)
    {
        if(arr[i] > arr[(i-1)/2])
        {
            int j = i;

            while(arr[j] > arr[(j - 1)/ 2])
            {
                swap(&arr[j],&arr[(j - 1)/2]);
                j = (j - 1)/2;
            }
        }
    }
}

void Heap_Sort(int *arr,int size)
{
    buildMaxHeap(arr,size);

    for(int i = size - 1;i > 0;i--)
    {
        swap(&arr[0],&arr[i]);

        int j = 0,index;

        do
        {
            index = (2 * j  + 1);
            printf("%d\t",arr[index]);
            printf("%d\t",arr[index+1]);


            if(arr[index] < arr[index + 1] && index < (i - 1))
            {
                index++;
            }

            if(arr[j] < arr[index] && index < i)
            {
                swap(&arr[j],&arr[index]);
            }

            j = index;
        }while(index < i);
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
    printf("---------------------------------Heap Sort--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Heap_Sort(arr,size);
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}