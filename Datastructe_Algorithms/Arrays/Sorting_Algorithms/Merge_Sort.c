#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int min(int a,int b)
{
    return (a < b)? a : b;
}
// l is for left index and r is right index of the
// sub-array of arr to be sorted
void Merge_Sort(int arr[], int size)
{
    int current_size;
    int left_start;

    for(current_size = 1; current_size <= size - 1;current_size = 2*current_size)
    {
        for(left_start = 0;left_start < size - 1;left_start = left_start + 2*current_size)
        {
            int mid = min(left_start+current_size - 1,size - 1);
            int right_end = min(left_start+2*current_size - 1,size - 1);

            merge(arr,left_start,mid,right_end);
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
    printf("---------------------------------Merge Sort--------------------------------\n");
    int size = 0;
    int *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (int*)malloc(sizeof(int)*size);

    Accept(arr,size);
    Display(arr,size);

    Merge_Sort(arr,size);
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}