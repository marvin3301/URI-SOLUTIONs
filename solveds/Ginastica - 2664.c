#include <stdio.h>

#define P 1000000007

long long int val[51][100001];

int main()
{
    int t,min,max,j,i;

    scanf("%d%d%d",&t,&min,&max);

    for(j=min; j<=max; j++)
    {
        val[0][j]=1;
    }
    for(i=1; i<t; i++)
    {
        for(j=min; j<=max; j++)
        {
            if(j > min && j < max)
            {
                val[i][j]=val[i-1][j-1]+val[i-1][j+1];

            }
            else if(j == min)
            {
                val[i][j]=val[i-1][j+1];
            }
            else if(j == max)
            {
                val[i][j]=val[i-1][j-1];
            }
        }
    }

   unsigned long long int soma=0;

    for(j=min; j<=max; j++)
    {
        soma+=val[t-1][j];
        if(soma>P)
         soma%=P;
    }
    printf("%lld\n",soma);
}
