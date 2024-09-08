#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    float data;
    struct Node *next;
}NODE,*PNODE,**PPNODE;

int getBucketIndex(float value,int size)
{
    return value/size;
}

PNODE Insertion_Sort(PNODE list,int size)
{
    PNODE k,nodeList;

    if(list == NULL || list->next == NULL)
    {
        return list;
    }

    nodeList = list;
    k = list->next;
    nodeList->next = NULL;

    while(k != NULL)
    {
        PNODE ptr;
        if(nodeList->data > k->data)
        {
            PNODE temp;
            temp = k;
            k = k->next;
            temp->next = nodeList;
            nodeList = temp;
            continue;
        }

        for(ptr = nodeList;ptr->next != 0;ptr = ptr->next)
        {
            if(ptr->next->data > k->data)
            {
                break;
            }
        }

        if(ptr->next != NULL)
        {
            PNODE temp;
            temp = k;
            k = k->next;
            temp->next = ptr->next;
            ptr->next = temp;

            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = NULL;
            continue;
        }
    }

    return nodeList;
}

void Bucket_Sort(float *arr,int size)
{
    int i = 0,j = 0;

    PPNODE buckets;

    buckets = (PPNODE)malloc(sizeof(PNODE)*size);

    for(i = 0;i < size;i++)
    {
        buckets[i] = NULL;
    }

    for(i = 0;i < size;i++)
    {
        PNODE current;
        int pos = getBucketIndex(arr[i],size);
        current = (PNODE)malloc(sizeof(NODE));
        current->data = arr[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }

    for(i = 0;i < size;i++)
    {
        buckets[i] = Insertion_Sort(buckets[i],size);
    }

    for(j = 0,i = 0;i < size;i++)
    {
        PNODE node;
        node = buckets[i];
        while(node != NULL)
        {
            arr[j++] = node->data;
            node = node->next;
        }
    }

    return;
}

void Accept(float *arr,int size)
{
    int i = 0;
    printf("Enter the elements of array : \n");
    for(i = 0;i < size;i++)
    {
        scanf("%f",&arr[i]);
    }
}

void Display(float *arr,int size)
{
    int i = 0;
    printf("Elements of array are : \n");
    for(i = 0;i < size;i++)
    {
        printf("%f\t",arr[i]);
    }
    printf("\n");
}

int main()
{
    printf("---------------------------------Bucket Sort--------------------------------\n");
    int size = 0;
    float *arr = NULL;

    printf("Enter number of elements in the array : \n");
    scanf("%d",&size);

    arr = (float*)malloc(sizeof(float)*size);

    Accept(arr,size);
    Display(arr,size);

    Bucket_Sort(arr,size);
    
    Display(arr,size);

    printf("-----------------------------------------------------------------------------------\n");


    return 0;
}