#include <stdio.h>
#include <math.h>

long long int mdc(long long int a,long long int b)
{
    if(b==0) return a;

    return mdc(b,a%b);

}


long long int mmc(long long int a,long long int b)
{
    return a*b / mdc(a, b);
}

int main()
{
    long long int cont=-1,aux,a,i,n,l,pos=-1,b,k=0;

    scanf("%lld%lld",&n,&l);
    scanf("%lld",&b);

    k=b;

    for(i=1; i<n; i++)
    {
        scanf("%lld",&a);

        k= mmc(k,a);

    }


    for(i=1; i<=l; i++)
    {
        aux = mmc(i,k);

        if(aux>cont && aux<=l)
        {
            cont = aux;
            pos = i;
        }
    }

    printf("%lld\n",pos);

    return 0;
}
