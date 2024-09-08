//Find the largest among the three numbers 

#include<stdio.h>


int max1(int a,int b,int c)
{
    int max = (a > b) ? (a > c) ? a : (c > b) ? c : b : (b > c) ? b : c;

    return max;
}

int max2(int a,int b,int c)
{
    int max = 0;

    if((a > b) && (a > c))
    {
        max = a;
    }
    else if((b > a) && (b > c))
    {
        max = b;
    }
    else
    {
        max = c;
    }

    return max;
}
int main()
{
    int a = 11,b = 21,c = 51;

    int max = max2(a,b,c);
    printf("Maximum number is : %d\n",max);

    return 0;
}