//Normal selection sort does not maintain relative order of duplicate elements using this approach the order can be maintained

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Selection_Sort_Stable(int *arr,int size)
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

        int key = arr[min_index];

        //cannot shift elements from i + 1 to n because will shifting next element is lost so shift from n to i backwards
        for(j = min_index;j > i;j--)
        {
            arr[j] = arr[j - 1];
        }

        arr[i] = key;
        
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
    printf("---------------------------------Stable Selection Sort--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Selection_Sort_Stable(arr,size);   
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}