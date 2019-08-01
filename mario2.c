#include <stdio.h>

int armarios[100000];
int n,l;

int verifica(int inicio)
{
    int i=inicio;
    int posFinal = armarios[inicio] + n;

    while(1)
    {
        if(i < l && armarios[i] < posFinal) i++;
        else break;
    }

    return i-inicio;
}

int melhorSeq()
{
    int i;
    int MaiorSeqPossivel = 0;
    int indFinal = l-1;

    while(indFinal > 0 && armarios[indFinal] > armarios[l-1]-n) indFinal--;
    if(indFinal < l-1 && armarios[indFinal] < armarios[l-1]-n) indFinal++;

    for(i=0; i <= indFinal; i++)
    {
        int x = verifica(i);
        if(x > MaiorSeqPossivel) MaiorSeqPossivel = x;
    }

    return n-MaiorSeqPossivel;
}

int main()
{
    int i;

    while(1)
    {
        scanf("%d %d", &n, &l);
        if(n == 0) break;
        for(i=0; i < l; i++) scanf("%d", &armarios[i]);

        printf("%d\n", melhorSeq());
    }

    return 0;
}

