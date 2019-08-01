#include <stdio.h>
#define MAX 112345

int c[MAX];

long long int gcd(int a, int b)
{
    int z;
    while(b != 0)
    {
        z = a;
        a = b;
        b = z%b;
    }
    return a;
}

long long int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{

    int N, L;

    int i, resp=-1;
    long long int aux, cont=-1, acum;

    while(scanf("%d %d", &N, &L) != EOF)
    {
        for(i = 0; i < N; i++)
        {
            scanf("%d", &c[i]);
            acum = (i > 0) ? lcm(acum, c[i]) : c[i];
        }

        for(i = 1; i <= L; i++)
        {
            aux = lcm(i, acum);

            if(cont < aux && aux <= L)
            {
                resp = i;
                cont = aux;
            }
        }
       printf("%d\n", resp);
    }
    return 0;
}
