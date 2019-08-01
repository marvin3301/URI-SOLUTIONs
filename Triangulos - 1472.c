#include <stdio.h>
int n;

int binarysearch(int v[], int chave)
{
	int inf = 0;
	int sup = n - 1;
	int meio;

	while (inf <= sup)
    {
        meio = inf + (sup-inf)/2;
        if (chave == v[meio])
            return meio;
        else if (chave < v[meio])
            sup = meio-1;
        else
            inf = meio+1;
    }
    return -1;
}

int main ()
{
	int ans[100010];

	int acc,i;
	int medida;

	int qtde;

	while(scanf("%d",&n)!= EOF)
	{
		acc = 0;
		qtde = 0;
		for ( i = 0; i < n; i++)
		{
			scanf("%d",&medida);
			acc+=medida;
			ans[i] = acc;
		}
		if (acc % 3 != 0) printf("0\n");
		else
		{
			acc/=3;
			for ( i = 0 ; i < n; i++)
			{
				if (binarysearch(ans, ans[i]+acc) != -1)
					if (binarysearch(ans, ans[i]+2*acc) != -1) qtde++;
			}
			printf("%d\n",qtde);
		}
	}
}
