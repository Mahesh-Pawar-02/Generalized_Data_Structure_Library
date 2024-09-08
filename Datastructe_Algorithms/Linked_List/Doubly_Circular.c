#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* prev;
    int data;
    struct node* next;
}NODE,*PNODE,**PPNODE;

int count(PNODE head,PNODE tail)
{
    int icount = 0;
    if(head != NULL || tail != NULL)
    {
        do
        {
            icount++;
            head = head->next;
        }while(head != tail->next);
    }
    
    return icount;
}

void display(PNODE head,PNODE tail)
{
    printf("Elements of Doubly Circular Linked List are : \n");
    if(head != NULL || tail != NULL)
    {
        do
        {
            printf("%d<=>",head->data);
            head = head->next;
        }while(head != tail->next);
        printf("\n");
    }
    else
    {
        printf("Linked list is empty\n");
    }
}

void insert_last(PPNODE head,PPNODE tail,int no)
{

    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL || *tail == NULL)
    {
        *head = *tail = newn;
    }
    else
    {
        newn->prev = *tail;;
        (*tail)->next = newn;
        *tail = newn;
    }
    (*tail)->next = *head;
    (*head)->prev = *tail;

}

void insert_first(PPNODE head,PPNODE tail,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL || *tail == NULL)
    {
        *head = *tail = newn;
    }
    else
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }
    (*tail)->next = *head;
    (*head)->prev = *tail;
}

void insert_at_pos(PPNODE head,PPNODE tail,int no,int pos)
{
    int icount = count(*head,*tail);

    if(pos < 0 || pos > icount + 1)
    {
        printf("Invalid position\n");
    }
    else if(pos == 1)
    {
        insert_first(head,tail,no);
    }
    else if(pos == icount+1)
    {
        insert_last(head,tail,no);
    }
    else
    {
        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        PNODE temp = *head;
        for(int i = 1;i < pos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
}

void delete_first(PPNODE head,PPNODE tail)
{
    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = *tail;
        (*tail)->next = *head;
    }
}

void delete_last(PPNODE head,PPNODE tail)
{
    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = *tail = NULL;
    }
    else
    {
        *tail = (*tail)->prev;
        free((*tail)->next);
        (*head)->prev = *tail;
        (*tail)->next = *head;
    }
}

void delete_at_pos(PPNODE head,PPNODE tail,int pos)
{
    int icount = count(*head,*tail);
    if(pos < 0 || pos > icount)
    {
        printf("Invalid position\n");
    }
    else if(pos == 1)
    {
        delete_first(head,tail);
    }
    else if(pos == icount)
    {
        delete_last(head,tail);
    }
    else
    {
        PNODE temp = *head;

        for(int i = 0;i < pos - 2;i++)
        {
            temp = temp->next;
        }

        
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    insert_last(&head,&tail,10);
    insert_last(&head,&tail,20);
    insert_last(&head,&tail,30);
    insert_last(&head,&tail,40);
    insert_last(&head,&tail,50);
    insert_first(&head,&tail,60);
    insert_first(&head,&tail,70);
    insert_first(&head,&tail,80);
    insert_at_pos(&head,&tail,55,10);
    display(head,tail);


    delete_at_pos(&head,&tail,3);
    display(head,tail);


    return 0;
}