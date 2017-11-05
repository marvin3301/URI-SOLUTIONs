#include <stdio.h>

int w[1002];
void intercala (int v[],int p,int q,int r)
{
    int i,j,k = 0;

    i = p;
    j = q;
    while(i < q && j < r)
    {
        if(v[i] >= v[j])
            w[k++] = v[i++];
        else
        {
            w[k++] = v[j++];
        }
    }
    while(i < q) w[k++] = v[i++];
    while(j < r) w[k++] = v[j++];
    for (i = p; i < r; i++)
        v[i] = w[i-p];
}

void Mergesort(int v[],int p,int r)
{
    int q;
    if(p < r-1)
    {
        q = (p+r)/2;
        Mergesort(v,p,q);
        Mergesort(v,q,r);
        intercala(v,p,q,r);

    }

}

int vet[1005];

int verifica(int a,int i,int f)
{
    int j,c=0;
    for(j=i; j<f; j++)
    {
        if(vet[j]==a)
        {
            c++;
        }
    }
    return c;
}

int main()
{
    int m,n,i,aux=0;
    scanf("%d%d",&m,&n);
    for(i=0; i<m; i++)
    {
        scanf("%d",&vet[i]);
    }

    Mergesort(vet,0,m);

    aux=verifica(vet[n-1],n,m);

    printf("%d\n",aux+n);

    return 0;
}
