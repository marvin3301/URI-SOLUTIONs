#include <stdio.h>

int ehPrimo(long long int N)
{
    long long int p;
    for(p = 2; p*p <= N; p++)
        if(N % p == 0) return 0;
    return 1;
}

int ehDespojado(long long int N)
{
    long long int PF = 2, cnt = 0;
    while(N != 1 && (PF*PF <= N))
    {
        if(N % PF == 0)
        {
            long long int D2 = N / PF;
            if(D2 != PF && ehPrimo(D2))
            {
                N /= D2;
                cnt++;
            }
            N /= PF;
            cnt++;
        }
        while(!ehPrimo(++PF));
    }

    if(N == 1 && cnt >= 2){
        return 1;
    }
    return 0;
}

long long int divDesp(long long int N)
{
    long long int cont = 0,i;
    for( i = 1; i*i <= N; i++)
    {
        if(N % i == 0)
        {
            if(ehDespojado(i)) cont++;
            if(ehDespojado(N/i) && (N/i != i)) cont++;
        }
    }
    return cont;
}

int main()
{
    long long int N;
    while(scanf("%lld", &N) != EOF)
    {
        printf("%lld\n", divDesp(N));
    }
    return 0;
}
