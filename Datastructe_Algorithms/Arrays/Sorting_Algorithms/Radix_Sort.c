#include<stdio.h>
#include<stdlib.h>

int getMax(int *arr,int size)
{
    int max = arr[0];
    for(int i = 1;i < size;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void Counting_Sort(int *arr,int size,int place)
{
    int output[size + 1];
    int max = (arr[0]/place) % 10;

    int i = 0;

    for(i = 1;i < size;i++)
    {
        if(((arr[i]/place) % 10)>max)
        {
            max = arr[i];
        }
    }

    int count[max + 1];

    for(i = 0;i < max;i++)
    {
        count[i] = 0;
    }

    for(i = 0;i < size;i++)
    {
        count[(arr[i]/place) % 10]++;
    }

    for(i = 1;i < 10;i++)
    {
        count[i] += count[i - 1];
    }

    for(i = size - 1;i >= 0;i--)
    {
        output[count[(arr[i]/place)%10] - 1] = arr[i];
        count[(arr[i]/place)%10]--;
    }

    for(i = 0;i < size;i++)
    {
        arr[i] = output[i];
    }
}


void Radix_Sort(int *arr,int size)
{
    int max = getMax(arr,size);

    for(int place = 1; max / place > 0;place *= 10)
    {
        Counting_Sort(arr,size,place);
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
    printf("---------------------------------Radix Sort--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Radix_Sort(arr,size);
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}