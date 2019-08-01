#include <stdio.h>
#include <math.h>

int vet[1000000];

int contains(int *vet,int n,int i)
{
    int j=0;
    for(j=0; j<n; j++)
    {
        if(vet[j]==i)
        {
            return 0;
        }
    }

    return 1;
}

void verifica(int *vet,int n, int m)
{

    int k=0,contador=0;
    long long int j=2,i;

    while(contador<m)
    {
        int x=j;
        for(i=0; i<sqrt(j); i++)
        {
            if(j%i==0)
            {
                if(contains(vet,n,i))
                {
                    k++;
                }
                j/=i;
            }

            if(contador==m)
            {
                printf("%lld\n",x);
                break;
            }



        }
        if(k==0)
        {
            contador++;
        }
        else k=0;
        j=x+1;

    }


}

int main ()
{

    int m,n,i,j;

    scanf("%d%d",&n,&m);

    while(1)
    {
        if(m==0 && n==0) break;

        for(i=0; i<n; i++)
        {
            scanf("%d",&vet[i]);

        }

        verifica(vet,n,m);


        scanf("%d%d",&n,&m);
    }



    return 0;
}
