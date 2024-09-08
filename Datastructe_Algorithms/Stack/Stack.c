#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    
}NODE,*PNODE,**PPNODE;


void push(PPNODE head,int no)
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

int pop(PPNODE head)
{
    if(*head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        PNODE temp = *head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        int iret = temp->next->data;
        free(temp->next);
        temp->next = NULL;
        return iret;
    }
}

void display(PNODE head)
{
    if(head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Elements of stack are : \n");
        while(head != NULL)
        {
            printf("%d->",head->data);
            head = head->next;
        }
        printf("NULL\n");
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
    push(&top,10);
    push(&top,20);
    push(&top,30);
    push(&top,40);
    push(&top,50);
    display(top);

    pop(&top);
    pop(&top);

    display(top);

    return 0;
}