#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    
}NODE,*PNODE,**PPNODE;


void enqueue(PPNODE head,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        PNODE temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    
}

int dequeue(PPNODE head)
{
    if(*head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        PNODE temp = *head;
        int iret = temp->data;
        *head = (*head)->next;
        free(temp);
        return iret;
    }
}

void display(PNODE head)
{
    if(head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        printf("Elements of queue are : \n");
        while(head != NULL)
        {
            printf("<-%d",head->data);
            head = head->next;
        }
        printf("<-NULL\n");
    }
}

int count(PNODE head)
{
    int icount = 0;
    while(head != NULL)
    {
        icount++;
        head = head->next;
    }
    return icount;
}

int main()
{
    PNODE top = NULL;
    enqueue(&top,10);
    enqueue(&top,20);
    enqueue(&top,30);
    enqueue(&top,40);
    enqueue(&top,50);
    display(top);

    dequeue(&top);
    dequeue(&top);

    display(top);

    return 0;
}