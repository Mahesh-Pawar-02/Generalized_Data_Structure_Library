//Program for implementing hash table and collision avoidance using open hashing

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

typedef struct HashMap
{
    int numOfElements;
    int Capacity;

    struct node** HashTable;
}HASH,*PHASH,**PPHASH;

void initializeHashMap(PHASH mp)
{
    mp->Capacity = 10;
    mp->numOfElements = 0;

    mp->HashTable = (PPNODE)malloc(sizeof(PNODE)*mp->Capacity);
}

int hash(int key)
{
    return key % SIZE;
}

void setNode(PNODE newn,int value)
{
    newn->next = NULL;
    newn->data = value;
}

void insert(PHASH mp,int value)
{
    int index = hash(value);
    
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    setNode(newn,value);

    //no collision
    if(mp->HashTable[index] == NULL)
    {
        mp->HashTable[index] = newn;
    }
    else
    {
        //collision
        //insert newnode at first
        newn->next = mp->HashTable[index];
        mp->HashTable[index] = newn;
    }
    mp->numOfElements++;
}

void delete(PHASH mp,int value)
{
    int index = hash(value);

    PNODE curr = mp->HashTable[index];
    PNODE prev = NULL;


    while(curr != NULL)
    {
        if(curr->data == value)
        {
            //head node delete
            if(curr == mp->HashTable[index])
            {
                mp->HashTable[index] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    mp->numOfElements--;


}

int search(PHASH mp,int value)
{
    int index = hash(value);

    PNODE temp = mp->HashTable[index];

    while(temp != NULL)
    {
        //key found
        if(temp->data == value)
        {
            return index;
        }
        temp = temp->next;
    }

    //no key found
    return -1;
}

int main()
{
    printf("---------------------------Hash Table with open hashing---------------------------------\n");
    int arr[] = {12,43,3,44,28,50,99,24,67,89};

    //object which has a pointer to the hashtable inside it and capacity of hashtable
    PHASH mp = (PHASH)malloc(sizeof(HASH));
    initializeHashMap(mp);

    
    for(int i = 0;i < 10;i++)
    {
        insert(mp,arr[i]);
    }

    printf("%d\n",search(mp,3));
    printf("%d\n",search(mp,-99));

    delete(mp,89);
    printf("%d\n",search(mp,89));
    printf("----------------------------------------------------------------------------------------\n");

    return 0;
}