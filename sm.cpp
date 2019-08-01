#include <stdio.h>

using namespace std;

long long int fatorial(long long int n)
{
    long long int j;
    if(n==0) return 1;
    for(j = 1; n > 1; n = n - 1)
        j = j * n;

}

int main()
{
    long long int fat, n;

    while(scanf("%lld%lld",&fat,&n)!=EOF)
    {
        printf("%lld\n",fatorial(fat)+fatorial(n));

    }

    return 0;
}
