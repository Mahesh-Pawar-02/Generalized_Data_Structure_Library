//Datastructures in cpp

#include<iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////////
// Structure for singly linear and circular
/////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

/////////////////////////////////////////////////////////////////////////////
// Structure for doubly linear and circular
/////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

/////////////////////////////////////////////////////////////////////////////
// Structure for Binary Search Tree
/////////////////////////////////////////////////////////////////////////////
template <class T>
struct NodeB
{
    T data;
    struct NodeB *lchild;
    struct NodeB *rchild;
};

/////////////////////////////////////////////////////////////////////////////
//Class of singly linearlinkedlist       
/////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> * first;
        int iCount;

        SinglyLL();
        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int FirstOccurence(T);
        int LastOccurence(T);
        T Minimum();
        T Maximum();
        T Summation();
        int Frequency(T);

};

template<class T>
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked list are: "<<"\n";

    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn-> data = no;
    newn-> next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn -> next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>:: InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn-> data = no;
    newn-> next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp -> next = newn;
    }
    iCount++;
}


template <class T>
void SinglyLL<T>:: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> * temp = first;

        first = first -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>:: DeleteLast()
{

    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> * temp = first;

        while(temp -> next -> next != NULL)
        {
            temp = temp->next;
        }

        delete temp -> next;;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>:: InsertAtPos(T no,int iPos)
{
    int iCount1 = Count();

    if((iPos < 1)||(iPos > iCount1+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount1+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn -> data = no;
        newn -> next = NULL;

        for(int iCnt = 1;iCnt < iPos - 1;iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>:: DeleteAtPos(int iPos)
{
    int iCount1 = Count();

    if((iPos < 1)||(iPos > iCount1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount1)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for(int iCnt = 1;iCnt < iPos - 1;iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1 -> next -> next;
        delete temp1 -> next;
        temp1->next = temp2;

        iCount--;
    }
}

template<class T>
int SinglyLL<T>::FirstOccurence(T No)
{
    NodeS<T> * temp = first;
    int iPos = -1,iCnt = 1;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }

    return iPos;    
}


template<class T>
int SinglyLL<T>::LastOccurence(T No)
{
    NodeS<T> * temp = first;
    int iPos = -1,iCnt = 1;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
        }
        iCnt++;
        temp = temp->next;
    }

    return iPos;
}

template<class T>
T SinglyLL<T>::Minimum()
{
    NodeS<T> * temp = first;
    T Min = temp->data;
    while(temp != NULL)
    {
        if(temp->data < Min)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }

    return Min;
}

template<class T>
T SinglyLL<T>::Maximum()
{

    NodeS<T> * temp = first;
    T Max = temp->data;
    while(temp != NULL)
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }

    return Max;
}

template<class T>
T SinglyLL<T>::Summation()
{
    NodeS<T> * temp = first;
    T Sum = (T)0;
    while(temp != NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return Sum;
}

template<class T>
int SinglyLL<T>::Frequency(T No)
{    
    NodeS<T> * temp = first;
    int iCount = 0;
    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iCount++;
        }
        temp = temp->next;
    }

    return iCount;
}


/////////////////////////////////////////////////////////////////////////////
//Class of singly circular linkedlist       //14
/////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

        SinglyCL();
        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);


        int FirstOccurence(T);
        int LastOccurence(T);
        T Minimum();
        T Maximum();
        T Summation();
        int Frequency(T);

};

template<class T>
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements of Singly Circular Linked list are: "<<"\n";
    NodeS<T> * temp = first;

    if((first != NULL)&&(last != NULL))
    {
        do
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp->next;
        }while(temp != last -> next);
        cout<<"\n";
    }
    else
    {
        cout<<"LinkedList is empty"<<"\n";
    }
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn -> next = first;
        first = newn;
    }
    last -> next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>:: InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        last = last -> next;
    }
    last -> next = first;
    iCount++;

}

template <class T>
void SinglyCL<T>:: DeleteFirst()
{
    NodeS<T> * temp = first;
    
    if((first == NULL)&&(last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;
        first = first -> next;
        delete temp;
        last -> next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>:: DeleteLast()
{NodeS<T> * temp = first;
    
    if((first == NULL)&&(last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;
        last -> next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>:: InsertAtPos(T no,int iPos)
{

    int iCount1 = Count();

    if((iPos < 1)||(iPos > iCount1+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount1+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn -> data = no;
        newn -> next = NULL;

        for(int iCnt = 1;iCnt < iPos - 1;iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>:: DeleteAtPos(int iPos)
{

    int iCount1 = Count();

    if((iPos < 1)||(iPos > iCount1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount1)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for(int iCnt = 1;iCnt < iPos - 1;iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1 -> next -> next;
        delete temp1 -> next;
        temp1->next = temp2;

        iCount--;
    }
}


template <class T>
int SinglyCL<T> :: FirstOccurence(T No)
{
    NodeS<T> * temp = first;
    int iPos = -1,iCnt = 1;

    do
    {
        if(temp->data == No)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }while(temp != last->next);
    
    return iPos;
}

template <class T>
int SinglyCL<T> ::LastOccurence(T No)
{
    NodeS<T> * temp = first;
    int iPos = -1,iCnt = 1;
    do
    {
        if(temp->data == No)
        {
            iPos = iCnt;
        }
        iCnt++;
        temp = temp->next;
    }while(temp != last->next);
    
    return iPos;
}

template <class T>
T SinglyCL<T> :: Minimum()
{
    NodeS<T> * temp = first;
    T Min = temp->data;
    do
    {
        if(temp->data < Min)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }while(temp != last->next);
    
    return Min;
}

template <class T>
T SinglyCL<T> :: Maximum()
{
    NodeS<T> * temp = first;
    T Max = temp->data;
    do
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }while(temp != last->next);
    
    return Max;
}

template <class T>
T SinglyCL<T> :: Summation()
{
    NodeS<T> * temp = first;
    T Sum = (T)0;
    do
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }while(temp != last->next);
    
    return Sum;
}

template <class T>
int SinglyCL<T> :: Frequency(T No)
{
    NodeS<T> * temp = first;
    int iFrequency = 0;

    do
    {
        if(temp->data == No)
        {
            iFrequency++;
        }
        temp = temp->next;
    }while(temp != last->next);
    
    return iFrequency;

}


/////////////////////////////////////////////////////////////////////////////
//Class of doubly linear linkedlist       //14
/////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        int iCount;

        DoublyLL();
        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int FirstOccurence(T);
        int LastOccurence(T);
        T Minimum();
        T Maximum();
        T Summation();
        int Frequency(T);
};
template<class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    cout<<"Elements of Doubly Linked List are : \n";

    if(first == NULL)
    {
        cout<<"LinkedList is empty\n";
    }
    else
    {
        NodeD<T> * temp = first;

        cout<<"NULL <=> ";
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" | <=> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }
    cout<<"\n";

}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn -> next = first;
        first -> prev = newn;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>:: InsertLast(T no)
{
    NodeD<T> * temp = first;

    while(temp -> next != NULL)
    {
        temp = temp->next;
    }
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp -> next = newn;
        newn -> prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>:: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first -> next;
        delete first -> prev;
        first -> prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>:: DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> *temp = first;

        while(temp-> next -> next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>:: InsertAtPos(T no,int iPos)
{
    int iCount1 = Count();

    if((iPos < 1)||(iPos > iCount1 + 1))
    {
        cout<<"Incorrect position \n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount1 + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * newn = new NodeD<T>;
        NodeD<T> * temp = first;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        for(int iCnt = 1; iCnt < iPos -1;iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        newn -> prev = temp;
        temp -> next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>:: DeleteAtPos(int iPos)
{
    int iCount1 = Count();

    if((iPos < 1)||(iPos > iCount1))
    {
        cout<<"Incorrect position \n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount1)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = first;

        for(int iCnt = 1; iCnt < iPos - 1;iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        iCount--;
    }
}


template <class T>
int DoublyLL<T> :: FirstOccurence(T No)
{
    NodeD<T> * temp = first;
    int iPos = -1,iCnt = 1;
    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }

    return iPos;
}

template <class T>
int DoublyLL<T> ::LastOccurence(T No)
{
    NodeD<T> * temp = first;
    int iPos = -1,iCnt = 1;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
        }
        iCnt++;
        temp = temp->next;
    }

    return iPos;
}

template <class T>
T DoublyLL<T> :: Minimum()
{
    NodeD<T> * temp = first;
    T Min = temp->data;

    while(temp != NULL)
    {
        if(temp->data < Min)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }

    return Min;
}

template <class T>
T DoublyLL<T> :: Maximum()
{
    NodeD<T> * temp = first;
    T Max = temp->data;

    while(temp != NULL)
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }

    return Max;
}

template <class T>
T DoublyLL<T> :: Summation()
{
    NodeD<T> * temp = first;
    T Sum = (T)0;

    while(temp != NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }

    return Sum;
}

template <class T>
int DoublyLL<T> :: Frequency(T No)
{
    NodeD<T> * temp = first;
    int iFrequency = 0;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iFrequency++;
        }
        temp = temp->next;
    }

    return iFrequency;
}

/////////////////////////////////////////////////////////////////////////////
//Class of doubly circular linkedlist       //14
/////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

        DoublyCL();
        void Display();
        int Count();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int FirstOccurence(T);
        int LastOccurence(T);
        T Minimum();
        T Maximum();
        T Summation();
        int Frequency(T);

};

template <class T>
DoublyCL<T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    cout<<"Elements of Doubly Circular Linked List are : \n";
    if((first == NULL)&&(last == NULL))
    {
        cout<<"Linked List is empty\n";
    }
    else
    {
        NodeD<T> * temp = first;

        for(int iCnt = 1; iCnt <= iCount;iCnt++)
        {
            cout<<"<=>|"<<temp->data<<"|";
            temp = temp->next;
        }
    }
    cout<<"<=>";
    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn -> data = no;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
        
    }
    first->prev = last;
    last->next = first;
    iCount++;
}

template <class T>
void DoublyCL<T>:: InsertLast(T no)
{

    NodeD<T> * newn = new NodeD<T>;

    newn -> data = no;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }
    first->prev = last;
    last->next = first;
    iCount++;
}

template <class T>
void DoublyCL<T>:: InsertAtPos(T no,int iPos)
{
    int iCount1 = Count();

    if((iPos < 1)||(iPos > iCount1 + 1))
    {
        cout<<"Incorrect position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount1 + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * temp = first;

        for(int iCnt = 1;iCnt < iPos -1;iCnt++)
        {
            temp = temp->next;
        }

        NodeD<T> * newn = new NodeD<T>;

        newn -> data = no;

        newn -> next = temp->next;
        temp -> next -> prev = newn;
        
        temp -> next = newn;
        newn -> prev = temp;
        
        iCount++;
    }
}

template <class T>
void DoublyCL<T>:: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == last -> next)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeD<T> * temp = first;
        first = first -> next;
      
        delete temp;

        last -> next = first;
        first -> prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>:: DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == last -> next)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeD<T> * temp = last;
        last = last -> prev;
      
        delete temp;

        last -> next = first;
        first -> prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>:: DeleteAtPos(int iPos)
{
    int iCount1 = Count();

    if((iPos < 1)||(iPos > iCount1))
    {
        cout<<"Incorrect position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount1)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = first;

        for(int iCnt = 1;iCnt < iPos -1;iCnt++)
        {
            temp = temp->next;
        }
        
        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        iCount--;
    }
}

template <class T>
int DoublyCL<T> :: FirstOccurence(T No)
{
    NodeD<T> * temp = first;
    int iPos = -1;
    for(int iCnt = 1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
            break;
        }
        temp = temp->next;
    }
    return iPos;
}

template <class T>
int DoublyCL<T> ::LastOccurence(T No)
{

    NodeD<T> * temp = first;
    int iPos = -1;
    for(int iCnt = iCount;iCnt >= 1;iCnt--)
    {
        if(temp->data == No)
        {
            iPos = iCnt;
            break;
        }
        temp = temp->prev;
    }
    return iPos;
}

template <class T>
T DoublyCL<T> :: Minimum()
{
    NodeD<T> * temp = first;
    T Min = temp->data;
    for(int iCnt = 1;iCnt <= iCount;iCnt++)
    {
        if(temp->data < Min)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }
    return Min;
}

template <class T>
T DoublyCL<T> :: Maximum()
{
    NodeD<T> * temp = first;
    T Max = temp->data;
    for(int iCnt = 1;iCnt <= iCount;iCnt++)
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }
    return Max;
}

template <class T>
T DoublyCL<T> :: Summation()
{
    NodeD<T> * temp = first;
    T Sum = (T)0;
    for(int iCnt = 1;iCnt <= iCount;iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }
    return Sum;
}

template <class T>
int DoublyCL<T> :: Frequency(T No)
{

    NodeD<T> * temp = first;
    int iFrequency = 0;
    for(int iCnt = 1;iCnt <= iCount;iCnt++)
    {
        if(temp->data == iFrequency)
        {
            iFrequency++;
        }
        temp = temp->next;
    }
    return iFrequency;
}

///////////////////////////////////////////////////////////////////////////////////
//      Stack       //4
///////////////////////////////////////////////////////////////////////////////////
template <class T>
class Stack
{
    public :
        int iCount;
        NodeS<T> * first;

    Stack();
    void Push(T);
    T Pop();
    void Display();
    int Count();
};

template <class T>
Stack<T> :: Stack()
{
    iCount = 0;
    first = NULL;
}

template <class T>
void Stack<T> :: Push(T No)
{
    NodeS<T> * newn = new NodeS<T>;
    newn -> data = No;
    newn -> next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> * temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
T Stack<T> :: Pop()
{
    T Value = (T)0;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> * temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;

    return Value;
}

template <class T>
void Stack<T> :: Display()
{
    if(first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    cout<<"Elements of stack are : \n";

    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////
//      Queue       //4
///////////////////////////////////////////////////////////////////////////////////
template <class T>
class Queue
{
    public : 
        int iCount;
        NodeS<T> * first;

        Queue();
        void Display();
        int Count();
        void Enqueue(T);
        T Dequeue();

};

template <class T>
Queue<T> :: Queue()
{
    iCount = 0;
    first = NULL;   
}

template <class T>
void Queue<T> :: Display()
{
    if(first == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    NodeS<T> * temp = first;

    cout<<"Elements of queue are : \n";
    for(int iCnt = 1;iCnt <= iCount;iCnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
}

template <class T>
int Queue<T> :: Count()
{
    return iCount;
}

template <class T>
void Queue<T> :: Enqueue(T No)
{
    NodeS<T> * newn = new NodeS<T>;
    newn->data = No;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> * temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T> :: Dequeue()
{
    T Value;

    if(first == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(first->next == NULL)
    {
        Value = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> * temp = first;

        Value = first->data;
        first = first->next;
        delete temp;
    }
    iCount--;

    return Value;
}

///////////////////////////////////////////////////////////////////////////////////
//      Binary Search Tree      //8
///////////////////////////////////////////////////////////////////////////////////
template <class T>
class BST
{
    public :
        static NodeB<T> * first;
        void Insert(T);
        void Preorder(NodeB<T> * temp = first);
        void Postorder(NodeB<T> * temp = first);
        void Inorder(NodeB<T> * temp = first);
        bool Search(T);
        int CountNodes(NodeB<T> * temp = first);
        int CountLeafNodes(NodeB<T> * temp = first);
        int CountParentNodes(NodeB<T> * temp = first);
};

template <class T>
NodeB<T>* BST<T> :: first = NULL;


template <class T>
void BST<T> :: Insert(T no)
{
    NodeB<T> *newn = NULL;
    NodeB<T> *temp = first;

    newn = new NodeB<T>;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(1)
        {
            if(no == temp->data)
            {
                cout<<"Duplicate element : Unable to insert\n";
                delete newn;
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

template <class T>
void BST<T> :: Preorder(NodeB<T> * temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<"\t";
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

template <class T>
void BST<T> :: Postorder(NodeB<T> * temp)
{
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout<<temp->data<<"\t";
    }
}

template <class T>
void BST<T> :: Inorder(NodeB<T> * temp)
{
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        cout<<temp->data<<"\t";
        Inorder(temp->rchild);
    }
}

template <class T>
bool BST<T> :: Search(T No)
{
    NodeB<T> * temp = first;
    bool bflag = false;
    if(first == NULL)
    {
        cout<<"Tree is empty\n";
        return bflag;
    }

    while(temp != NULL)
    {
        if(No == temp->data)
        {
            bflag = true;
            break;
        }
        else if(No > temp->data)
        {
            temp = temp->rchild;
        }
        else if(No < temp->data)
        {
            temp = temp->lchild;
        }
    }
    return bflag;
}

template <class T>
int BST<T> :: CountNodes(NodeB<T> * temp)
{
    static int iCnt = 0;

    if(temp != NULL)
    {
        iCnt++;
        CountNodes(temp->lchild);
        CountNodes(temp->rchild);
    }

    return iCnt;
}

template <class T>
int BST<T> :: CountLeafNodes(NodeB<T> * temp)
{
    static int iCnt = 0;

    if(temp != NULL)
    {
        if((temp->lchild == NULL)&&(temp->rchild == NULL))
        {
            iCnt++;
        }
        CountLeafNodes(temp->lchild);
        CountLeafNodes(temp->rchild);
    }

    return iCnt;
}

template <class T>
int BST<T> :: CountParentNodes(NodeB<T> * temp)
{
    static int iCnt = 0;

    if(temp != NULL)
    {
        if((temp->lchild != NULL)&&(temp->rchild != NULL))
        {
            iCnt++;
        }
        CountParentNodes(temp->lchild);
        CountParentNodes(temp->rchild);
    }

    return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////
//      Searching       //3
///////////////////////////////////////////////////////////////////////////////////
template <class T>
class Searching
{
    public : 
        int iSize;
        T *Arr;

        Searching(int);
        ~Searching();
        void Accept();
        void Display();
        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);

};

template <class T>
Searching<T> :: Searching(int No)
{
    this->iSize = No;
    this->Arr = new T[iSize];
}

template <class T>
Searching<T> :: ~Searching()
{
    delete []Arr;
}

template <class T>
void Searching<T> ::  Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0;iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void Searching<T> ::  Display()
{
    cout<<"Elements are : \n";
    for(int iCnt = 0;iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
bool Searching<T> ::  LinearSearch(T No)
{
    bool bflag = false;
    for(int iCnt = 0;iCnt < iSize; iCnt++)
    {
        if(No == Arr[iCnt])
        {
            bflag = true;
            break;
        }
    }
    return bflag;
}

template <class T>
bool Searching<T> ::  BidirectionalSearch(T No)
{
    int iStart = 0;
    int iEnd = iSize - 1;
    bool bflag = false;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No)||(Arr[iEnd] == No))
        {
            bflag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return bflag;
}

template <class T>
bool Searching<T> ::  BinarySearch(T No)
{
    int iStart = 0, iEnd = iSize - 1,iMid = 0;
    bool bflag = false;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart)/2;
        if((Arr[iMid] == No)||(Arr[iStart] == No)||(Arr[iEnd] == No))
        {
            bflag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > No)
        {
            iEnd = iMid - 1;
        }
    }
    return bflag;
}

///////////////////////////////////////////////////////////////////////////////////
//      Sorting     //5
///////////////////////////////////////////////////////////////////////////////////
template <class T>
class Sorting
{
    public : 
        T *Arr;
        int iSize;

        Sorting(int);
        ~Sorting();
        void Accept();
        void Display();
        bool CheckSorted();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();


};

template <class T>
Sorting<T> :: Sorting(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
Sorting<T> :: ~Sorting()
{
    delete []Arr;
}

template <class T>
void Sorting<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0;iCnt < iSize;iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void Sorting<T> :: Display()
{
    cout<<"Elements of array are : \n";  
    for(int iCnt = 0;iCnt < iSize;iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
bool Sorting<T> :: CheckSorted()
{
    int iCnt = 0;
    bool flag = true;

    for(iCnt = 0;iCnt < iSize - 1; iCnt++)
    {
        if(Arr[iCnt] <= Arr[iCnt + 1])
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}

template <class T>
void Sorting<T> :: BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    for(i  = 0;i < iSize; i++)
    {
        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }
}

template <class T>
void Sorting<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    for(i  = 0;i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
        cout<<"Data after pass : "<<i + 1<<"\n";
        Display();

    }
}

template <class T>
void Sorting<T> :: SelectionSort()
{
    T temp;
    int i = 0, j = 0,min_index = 0;

    for(i  = 0;i < iSize - 1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

template <class T>
void Sorting<T> :: InsertionSort()
{
    int i = 0, j = 0;
    T selected = 0;

    for(i  = 1;i < iSize; i++)
    {
        for(j = i - 1,selected = Arr[i]; ((j >= 0)&&(Arr[j] > selected)); j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = selected;
    }
}

///////////////////////////////////////////////////////////////////////////////////
//      Entry point function
///////////////////////////////////////////////////////////////////////////////////
int main()
{

    return 0;
}