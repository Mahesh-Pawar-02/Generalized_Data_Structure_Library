#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int Jump_Search(int *arr,int size,int search)
{
    int step = sqrt(size);
    int jump = step,i = 0;

    while(arr[jump] <= search && jump < size)
    {
        i = jump;
        jump += step;

        if(jump > size-1)
        {
            return -1;
        }
    }

    while(i < jump)
    {
        if(arr[i] == search)
        {
            return i;
        }
        i++;
    }

    return -1;

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
    printf("---------------------------Jump Search------------------------------\n");
    int size = 0,search = 0;
    int *arr = NULL;


    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    printf("Enter the element you want to search : \n");
    scanf("%d",&search);

    int iRet = Jump_Search(arr,size,search);   
    if(iRet >= 0)
    {
        printf("Element found at index : %d\n",iRet);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("----------------------------------------------------------------------\n");


    return 0;
}