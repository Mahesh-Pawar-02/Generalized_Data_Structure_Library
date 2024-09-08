//program to check whether a number is prime or not

#include<stdio.h>
#include<stdbool.h>

bool checkPrime(int no)
{
    int i = 0;
    bool flag = true;

    for(i = 2;i <= no/2;i++)
    {
        if(no%i == 0)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main()
{
    int no = 11;

    bool bRet = checkPrime(no);
    if(bRet == true)
    {
        printf("%d is a prime number\n",no);
    }
    else
    {
        printf("%d is not a prime number\n",no);
    }
    return 0;
}