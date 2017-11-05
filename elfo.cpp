#include<iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    string nome;
    int peso, idade ;
    float altura;
} renas;
renas vet[1001];

bool cmp(renas x, renas y)
{
    if(x.peso == y.peso)
        if(x.idade == y.idade)
            if(x.altura == y.altura)
                if(x.nome != y.nome)
                    return x.nome > y.nome;
                else
                    return x.nome < y.nome;
            else
                return x.altura < y.altura;
        else
            return x.idade < y.idade;
    else
        return x.peso > y.peso ;
}

int main()
{
    int n,l1,l2;

    cin >> n;

    for(int j = 1 ; j <= n ; j++)
    {
        cin >> l1 >> l2;

        for(int i = 0; i < l1 ; i++)
        {
            cin >> vet[i].nome >> vet[i].peso >> vet[i].idade >> vet[i].altura;

        }
        sort(vet,vet+l1,cmp);

        printf("CENARIO {%d}\n", j);

        for(int i = 0; i < l2; i++)
        {
            printf("%d - ", i+1);
            cout << vet[i].nome << endl;
        }
    }
    return 0;
}
