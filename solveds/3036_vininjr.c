#include <stdio.h>
#include <math.h>

#define C 300000000

int main(int argc, char **argv)
{

    double V;
    scanf("%lf", &V);

    double result = 700.0 * (sqrt((C - V) / (C + V)) - 1.0) + 700.0;

    if (result < 400.0)
        puts("invisivel");
    else if (result < 425.0)
        puts("violeta");
    else if (result < 445.0)
        puts("anil");
    else if (result < 500.0)
        puts("azul");
    else if (result < 575.0)
        puts("verde");
    else if (result < 585.0)
        puts("amarelo");
    else if (result < 620.0)
        puts("laranja");
    else if (result < 750.0)
        puts("vermelho");
    else
        puts("invisivel");

    return 0;

}