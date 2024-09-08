//program to find a sub array which totals to given value sum if no such subarray return -1
//return the starting and ending indexes of the subarray

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *subArraySum(int *arr,int n,int sum)
{
    int *ret = calloc(sizeof(int),2);

    int last = 0;
    int start = 0;
    int currentSum = 0;
    bool flag = false;
    int i = 0,j = 0;

    for(i = 0;i < n;i++)
    {
        currentSum += arr[i];

        if(currentSum >= sum )
        {
            last = i;
        }

        while(sum < currentSum && start < last)
        {
            currentSum -= arr[start];
            start++;
        }

        if(currentSum == sum)
        {
            ret[0] = start;
            ret[1] = last;
            flag = true;
            break;
        }

        if(flag)
        {
            break;
        }
    }

    if(!flag)
    {
        ret[0] = -1;
    }

    return ret;

}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    
    int *ret = NULL;
    ret = subArraySum(arr,8,23);

    printf("%d\t%d\n",ret[0],ret[1]);   //2 5
    
    free(ret);

    return 0;
}