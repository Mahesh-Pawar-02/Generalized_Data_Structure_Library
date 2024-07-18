#include<iostream>
using namespace std;

template <class T>
class Array
{
    public:
        T *Arr;
        int Size;

        Array(int Length);
        ~Array();
        void Accept();
        void Display();
        T Addition();
};

template <class T>
T Array<T> :: Addition()
{
    T Sum = 0;
    int iCnt = 0;

    for(iCnt = 0; iCnt < Size; iCnt++)
    {
        Sum = Sum + Arr[iCnt];
    }
    return Sum;
}

template <class T>
Array<T> :: Array(int Length)
{
    Size = Length;
    Arr = new T[Size];
}

template <class T>
Array<T> :: ~Array()
{
    delete []Arr;
}

template <class T>
void Array<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    int iCnt = 0;

    for(iCnt = 0; iCnt < Size; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void Array<T> :: Display()
{
    cout<<"Elements of the array are : \n";
    int iCnt = 0;

    for(iCnt = 0; iCnt < Size; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

int main()
{
    int Ret = 0;

    Array <int>obj(5);

    obj.Accept();
    obj.Display();
    
    Ret = obj.Addition();

    cout<<"Addition is : "<<Ret<<"\n";

    return 0;
}