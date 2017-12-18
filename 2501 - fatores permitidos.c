// questao incompleta, ta dando TLE
// qualquer ajuda é bem-vinda !!!

#include<stdio.h>
#include<stdlib.h>

 int vet[100005];

int maxDivide(int a, int b)
{
    while(a % b == 0)
        a = a/b;
    return a;
}

int ehFator(int num, int *v,int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        num = maxDivide(num,v[i]);
    }

    return (num == 1)? 1 : 0;
}

int Fator_Permitido(int n, int *primos,int tam)
{
    int i = 1;
    int count = 1;

    while (n >= count)
    {
        i++;
        if (ehFator(i,primos,tam))
            count++;
    }
    return i;
}

int main()
{
    int m,n,i;

    while(1)
    {
        scanf("%d%d",&m,&n);

        if(m==0 && n==0) break;

        for(i=0; i<m; i++)
        {
            scanf("%d",&vet[i]);
        }

        printf("%d\n",Fator_Permitido(n,vet,m));

    }

    return 0;
}
