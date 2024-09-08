#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}NODE,*PNODE,**PPNODE;


int count(PNODE head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void search(PNODE head,int no)
{
    int count = 1;
    while(head != NULL)
    {
        if(head->data == no)
        {
            printf("Element found at position : %d\n",count);
            break;
        }
        count++;
        head = head->next;
    }
    if(head == NULL)
    {
        printf("Element not found\n");
    }
}

void delete_first(PPNODE head)
{

    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        PNODE temp = *head;

        *head = (*head)->next;
        free(temp);
    }
}

void delete_last(PPNODE head)
{
    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        PNODE temp = *head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_at_pos(PPNODE head,int pos)
{
    int icount = count(*head);

    if(pos < 0 || pos > icount)
    {
        printf("Invalid position\n");
    }
    else if(pos == 1)
    {
        delete_first(head);
    }
    else if(pos == icount)
    {
        delete_last(head);
    }
    else
    {
        PNODE temp = *head;

        for(int i = 0;i < pos - 2;i++)
        {
            temp = temp->next;
        }
    
        PNODE tempX = temp->next;
        temp->next = temp->next->next;
        free(tempX);
    }
}

void insert_last(PPNODE head,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
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

void insert_first(PPNODE head,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
}

void insert_at_pos(PPNODE head,int no,int pos)
{
    int icount = count(*head);
    if(pos < 0 || pos > icount+1)
    {
        printf("Invalid position cannot insert node\n");
        return;
    }

    if(pos == 1)
    {
        insert_first(head,no);
        return;
    }
    else if(pos == icount+1)
    {
        insert_last(head,no);
        return;
    }
    else
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
            for(int i = 1;i < pos-1;i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
        }
    }
}

void display(PNODE head)
{
    printf("Elements of linked list are :\n");
    while(head != NULL)
    
    {
        printf("%d => ",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    PNODE head = NULL;
    PNODE head1 = NULL;

    insert_last(&head,10);
    insert_last(&head,20);
    insert_last(&head,30);
    insert_at_pos(&head,99,5);
    insert_first(&head,40);
    insert_first(&head,50);
    insert_first(&head,60);

    display(head);
    

    delete_last(&head);
    display(head);

    delete_at_pos(&head,2);
    display(head);

    delete_first(&head);
    display(head);
    delete_first(&head);
    display(head);


    return 0;
}