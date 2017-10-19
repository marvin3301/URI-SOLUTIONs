#include <bits/stdc++.h>

using namespace std;

#define INF 999999999 //0x3F3F3F3F

const int MN = 1035;
int n;

int data[MN];

int dp[MN][MN];
bool memo[MN][MN];
int solve(int l, int r)
{
    if(l>r)
        return 0;
    if(l==r)
        return 1;
    if(memo[l][r])
        return dp[l][r];
    int &ret=dp[l][r]=INF;
    ret=min(ret, 1+solve(l+1, r));
    ret=min(ret, 1+solve(l, r-1));
    if(data[l]==data[r])
        ret=min(ret, 1+solve(l+1, r-1));
    memo[l][r]=true;
    return ret;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    for(int t=1; t<=tt; t++)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", &data[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                memo[i][j]=false;
        printf("Caso #%d: %d\n", t, solve(0, n-1));
    }
    return 0;
}
