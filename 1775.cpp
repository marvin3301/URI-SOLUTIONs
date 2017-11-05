#include <bits/stdc++.h>

#define INF 999999999
#define MN 1001

using namespace std;

int n;

int sabores[MN];
int pd[MN][MN];
int memo[MN][MN];

int minimo(int a,int b){
    if(a>b) return b;
    return a;
}

int solucao(int a, int b)
{
    if(a>b)
        return 0;

    if(a==b)
        return 1;

    if(memo[a][b]==1)
        return pd[a][b];
    
    int &ret = pd[a][b];

    ret=minimo(ret, 1+solucao(a+1, b));

    ret=minimo(ret, 1+solucao(a, b-1));

    if(sabores[a]==sabores[b])
        ret=minimo(ret, 1+solucao(a+1, b-1));

    memo[a][b]=1;

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
            scanf("%d", &sabores[i]);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                memo[i][j]=0;
                pd[i][j]=INF;
            }

            printf("Caso #%d: %d\n", t, solucao(0, n-1));
        }
        return 0;
    }
