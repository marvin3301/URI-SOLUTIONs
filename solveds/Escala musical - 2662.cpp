#include <stdio.h>
#include <string>

using namespace std;

int orienta[12] = { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 };

string nome_nota[12] =
{
	"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol",
	"sol#", "la", "la#", "si"
};

int main()
{
	int N, nota,i,j;
	int bs[12];
	while(scanf("%d", &N) != EOF)
	{
		for(i=0; i<12; i++)
		{
			bs[i]=0;
		}
		while(N--)
		{
			scanf("%d", &nota);
			bs[(nota-1)%12] = 1;
			
		}

		int ans = -1;
		
		for(j = 0; j < 12; j++)
		{
			int aqui = 1;
			for(int i = 0; i < 12; i++)
			{
				if(bs[(j+i)%12] && orienta[j+i])
				{
					aqui = 0;
					break;
				}
			}
			if(aqui==1)
			{
				ans = j;
				break;
			}
		}
		if(ans > -1)
		{
			printf("%s\n",nome_nota[ans].c_str());

		}
		else
		{
			printf("desafinado\n");
		}
	}
	return 0;
}
