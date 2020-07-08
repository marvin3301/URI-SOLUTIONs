// https://www.urionlinejudge.com.br/judge/pt/problems/view/1286

#include <bits/stdc++.h> // standard template library (STL)

using namespace std;

int tabela[31][31];
int peso[31];
int valor[31];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); // truque para ler entradas grandes.

    int capacidade, n;

    while(1){
    	int soma,s;

    	cin >> n;
    	if(n==0) break;
    	cin >> capacidade;

    	for (int i = 1; i <= n; ++i)
    	{
    		cin >> valor[i] >> peso[i];
    	}

    	for (int i = 0; i <= n; ++i) tabela[0][i] = 0;

		for(int b = 1; b<=capacidade; b++){
			tabela[0][b] = 0;
			
			for(int i=1; i<=n; i++){
				s = tabela[i-1][b];
				
				if(peso[i] <= b){
					soma = tabela[i-1][b-peso[i]] + valor[i];
					if( s < soma){
						s = soma;
					}
				}
				
				tabela[i][b] = s;
			}
		}

		cout << tabela[n][c] << " min." << endl;

    }

    return 0;
}