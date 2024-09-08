#include<stdio.h>
#include<stdlib.h>

typedef struct hash
{
    int capacity;
    int numOfElements;
    int *table;
}HASH,*PHASH;

void initializeHashMap(PHASH mp)
{
    mp->capacity = 10;
    mp->numOfElements = 0;
    mp->table = (int *)calloc(sizeof(int),mp->capacity);
}

int hash(int key)
{
    return key % 10;
}

void insert(PHASH mp,int key)
{
    if(mp->numOfElements == mp->capacity)
    {
        printf("Hash table is full cannot insert new element\n");
        return;
    }

    int index = hash(key);

    while(mp->table[index] != 0 && mp->table[index] != -1)
    {
        index = hash(index+1);
    }

    mp->table[index] = key;
    mp->numOfElements++;
}

int search(PHASH mp,int key)
{
    if(mp->numOfElements == 0)
    {
        return -1;
    }

    int index = hash(key);
    while(mp->table[index] != 0 && mp->table[index] != -1)
    {
        if(mp->table[index] == key)
        {
            return index;
        }
        index = hash(index + 1);
    }

    return -1;
}

void delete(PHASH mp,int key)
{
    if(mp->numOfElements == 0)
    {
        printf("Hash table empty no element to delete\n");
        return;
    }

    int index = search(mp,key);

    if(index != -1)
    {
        mp->table[index] = -1;
        mp->numOfElements--;
    }
}



void displayTable(PHASH mp)
{
    printf("\n");

    for(int i = 0;i < mp->capacity;i++)
    {
        printf("%d\t",mp->table[i]);
    }
    printf("\n");
}
int main()
{
    printf("------------------------------Hash table using Linear Probing------------------------\n");
    
    int arr[] = {12,43,3,44,28,50,99,24,67,89};

    PHASH mp = (PHASH)malloc(sizeof(HASH));
    initializeHashMap(mp);

    for(int i = 0;i < 10;i++)
    {
        insert(mp,arr[i]);
    }

    displayTable(mp);

    printf("%d\n",search(mp,3));
    printf("%d\n",search(mp,-99));

    delete(mp,89);
    printf("%d\n",search(mp,89));

    displayTable(mp);
    printf("--------------------------------------------------------------------------------------\n");
    return 0;
}