#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
}NODE,*PNODE,**PPNODE;

void insert(PPNODE root,int val)
{
    PNODE temp = *root;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->left = NULL;
    newn->right = NULL;
    newn->data = val;

    if(*root == NULL)
    {
        *root = newn;
    }
    else
    {
        while(1)
        {
            if(val == temp->data)
            {
                printf("Duplicate element : Unable to insert\n");
                free(newn);
                break;
            }
            else if(val < temp->data)
            {
                if(temp->left == NULL)
                {
                    temp->left = newn;
                    break;
                }
                temp = temp->left;
            }
            else if(val > temp->data)
            {
                if(temp->right == NULL)
                {
                    temp->right = newn;
                    break;
                }
                temp = temp->right;
            }
        }
    }

}

bool search(PNODE root,int val)
{
    bool flag = false;
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return flag;
    }
    else
    {
        while(root != NULL)
        {
            if(val == root->data)
            {
                flag = true;
                break;
            }
            else if(val > root->data)
            {
                root = root->right;
            }
            else if(val < root->data)
            {
                root = root->left;
            }
        }
        return flag;
    }
}

void Preorder(PNODE root)
{
    if(root != NULL)
    {
        printf("%d\n",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(PNODE root)
{

    if(root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d\n",root->data);
    }
}

void Inorder(PNODE root)
{

    if(root != NULL)
    {
        Inorder(root->left);
        printf("%d\n",root->data);
        Inorder(root->right);
    }
}

int main()
{
    PNODE head = NULL;
    insert(&head,10);
    insert(&head,5);
    insert(&head,14);
    Preorder(head);
    printf("%d\n",search(head,15));

    return 0;
}