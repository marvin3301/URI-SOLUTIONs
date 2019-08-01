#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int m;

bool cmp_ipairs(int a, int b)
{
    if(a%2!=0 && b%2==0 && a%m==b%m)
    {
        return 1;
    }
    else if(a%2!=0 && b%2!=0 && a%m==b%m)
    {
        if(a>b)
        {
            return 1;
        }
        else return 0;
    }
    else if(a%2==0 && b%2==0 && a%m==b%m)
    {
        if(a>b)
        {
            return 0;
        }
        else return 1;
    }
    return(a%m<b%m)?1:0;
}

int main()
{
    int times, nums[100000],x;
    while(1)
    {
        scanf("%d%d",&times,&m);
        if((times && m)==0)
        {
            printf("%d %d\n",times,m);
            break;
        }
        for (x = 0; x < times; x++)
        {
            cin >> nums[x];
        }

        sort(nums, nums+times, cmp_ipairs);
        printf("%d %d\n",times,m);
        for (x = 0; x < times; x++)
        {
            printf("%d\n",nums[x]);
        }
    }
    return 0;
}
